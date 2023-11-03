#include "stdafx.h"
#include "railCoupling.h"

void normaliseCouplingCoeffs(SingleRailTest *railTestData);
void basicCouplingCalc(SingleRailTest *railTestData);
void iterativeCouplingCalc(SingleRailTest *railTestData);
void noneCouplingCalc(SingleRailTest *railTestData);

const int COUPLING_CALC_ITERATIONS=20;
const int ITERATIVE_CALC_OPTION=1;


int railCalculateCoupling(SingleRailTest *railTestData, couplingCalcOption option) {
	tic();
	TRACE("\nCoupling calculations\n"
		    "======== ============\n");
	switch (option) {
	case NONE:	
		noneCouplingCalc(railTestData);
		break;
	case BASIC: 
		basicCouplingCalc(railTestData);
		break;
	case ITERATIVE: 
		iterativeCouplingCalc(railTestData);
		break;
	default: 
		break;
	}
	//normalise them so that mean is unity
	normaliseCouplingCoeffs(railTestData);
/*	TRACE("Coupling calculation - first 10 values\n");
	TRACE("No.\tAmp.\tCoup.\n");
	for (int i=0;i<10;i++) {
		TRACE("%i.\t%f\t%f\n",	i,
								railTestData->m_RawData[i].m_Configurations.RawData.m_signalAmplitude,
								railTestData->m_Working.m_RawSpectralData[i].m_Configurations.Spectral.m_couplingCorrection);
	}*/
	TRACE("Time taken to do coupling calculation: %f secs\n",toc());
	return 1;
}

void noneCouplingCalc(SingleRailTest *railTestData) {
	TRACE("No coupling calculation (putting lots of ones into coupling compensation values)...\n");
	int numberTimeTraces=railTestData->m_RawData.GetSize();
	for (int i=0;i<numberTimeTraces;i++) {
		railTestData->m_Working.m_RawSpectralData[i].m_Configurations.Spectral.m_couplingCorrection=1.0;
	}
}

void basicCouplingCalc(SingleRailTest *railTestData) {
	TRACE("Basic coupling calculation...\n");
	int numberTimeTraces=railTestData->m_RawData.GetSize();
	for (int i=0;i<numberTimeTraces;i++) {
		if (railTestData->m_RawData[i].m_Configurations.RawData.m_signalAmplitude>0.0) {
		railTestData->m_Working.m_RawSpectralData[i].m_Configurations.Spectral.m_couplingCorrection
			= 1.0 / railTestData->m_RawData[i].m_Configurations.RawData.m_signalAmplitude;
		}
		else
		{
		railTestData->m_Working.m_RawSpectralData[i].m_Configurations.Spectral.m_couplingCorrection
			= 0.0;
		}
	}
}

void iterativeCouplingCalc(SingleRailTest *railTestData) {
	TRACE("Iterative coupling calculation...\n");
	//Principle 
	//
	//1. Start out with a transducer weighting vector transWeight all unity
	//2. Take the measured amplitudes from each time trace, Sij,
	//3. Sort them into amplitudes, transAmp, associated with 
	//   the transmitter and receiver - 
	//		ITERATIVE_CALC_OPTION==1
	//		transAmp(i) += sqrt((Sij)*transWeight(i)*transWeight(j))
	//		transAmp(j) += sqrt((Sij)*transWeight(i)*transWeight(j))
	//		ITERATIVE_CALC_OPTION==2
	//		transAmp(i) += (Sij)*transWeight(i)*transWeight(j)
	//		transAmp(j) += (Sij)*transWeight(i)*transWeight(j)
	//4. Work out new weightings
	//		ITERATIVE_CALC_OPTION==1
	//		transWeight(ij)=transWeight(ij)*idealValue(ij)/transAmp(ij)
	//		ITERATIVE_CALC_OPTION==2
	//		transWeight(ij)=transWeight(ij)*idealValue(ij)/sqrt(transAmp(ij))
	//5. Repeat 3 and 4
	//
	//note both ITERATIVE_CALC_OPTION options converge after about 15-20 iterations, but not to same value
	int numberTimeTraces=railTestData->m_RawData.GetSize();
	vectorDouble amplitude(numberTimeTraces);
	double meanAmplitude=0.0;
	for (int i=0;i<numberTimeTraces;i++) {
		amplitude[i]=railTestData->m_RawData[i].m_Configurations.RawData.m_signalAmplitude;
		meanAmplitude += amplitude[i];
	}
	meanAmplitude /= numberTimeTraces;
	for (i=0;i<numberTimeTraces;i++) {
		amplitude[i] /= meanAmplitude;
	}
	//need to work out how maximum transducer rows and positions
	int transRows=0;
	int transPositions=0;
	int txRowIndex, rxRowIndex, txPosIndex, rxPosIndex, txIndex, rxIndex;
	for (i=0;i<numberTimeTraces;i++) {
		txRowIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bTxRow;
		rxRowIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bRxRow;
		txPosIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bTxPos;
		rxPosIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bRxPos;
		transRows =(transRows>txRowIndex) ? transRows : txRowIndex;
		transRows =(transRows>rxRowIndex) ? transRows : rxRowIndex;
		transPositions = (transPositions>txPosIndex) ? transPositions : txPosIndex;
		transPositions = (transPositions>rxPosIndex) ? transPositions : rxPosIndex;
	}

	vectorDouble transWeight(1.0,transRows*transPositions);
	vectorDouble idealValue(1.0,transRows*transPositions);
	vectorDouble transAmp(0.0,transRows*transPositions);

	//main iteration loop
	for (int iters=0;iters<COUPLING_CALC_ITERATIONS;iters++) {
		//zero transAmp vector
		transAmp=vectorDouble(0.0,transRows*transPositions);
		//add up the transducer contributions based on current weighting
		for (i=0;i<numberTimeTraces;i++) {
			txRowIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bTxRow;
			rxRowIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bRxRow;
			txPosIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bTxPos;
			rxPosIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bRxPos;
			txIndex=matrixIndex(txRowIndex,txPosIndex,transRows,transPositions,1);
			rxIndex=matrixIndex(rxRowIndex,rxPosIndex,transRows,transPositions,1);
			if (ITERATIVE_CALC_OPTION==1) {
				transAmp[txIndex] += sqrt(amplitude[i] * transWeight[txIndex] * transWeight[rxIndex]);
				transAmp[rxIndex] += sqrt(amplitude[i] * transWeight[txIndex] * transWeight[rxIndex]);
			}
			if (ITERATIVE_CALC_OPTION==2) {
				transAmp[txIndex] += amplitude[i] * transWeight[txIndex] * transWeight[rxIndex];
				transAmp[rxIndex] += amplitude[i] * transWeight[txIndex] * transWeight[rxIndex];
			}
		}
		//update weighting
		for (i=0;i<transWeight.size();i++) {
			if (transAmp[i]>0.0) {
				if (ITERATIVE_CALC_OPTION==1) {
					transWeight[i] *= idealValue[i]/transAmp[i];
				}
				if (ITERATIVE_CALC_OPTION==2) {
					transWeight[i] *= idealValue[i]/sqrt(transAmp[i]);
				}
			}
		}
		//turn on to see progression of ith value
/*		i=0;
		txRowIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bTxRow;
		rxRowIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bRxRow;
		txPosIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bTxPos;
		rxPosIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bRxPos;
		txIndex=matrixIndex(txRowIndex,txPosIndex,transRows,transPositions,1);
		rxIndex=matrixIndex(rxRowIndex,rxPosIndex,transRows,transPositions,1);
		TRACE("%i Coupling: %f\n",iters,transWeight[txIndex] * transWeight[rxIndex]);*/
	}
	//put the values into railTestData
	for (i=0;i<numberTimeTraces;i++) {
		txRowIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bTxRow;
		rxRowIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bRxRow;
		txPosIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bTxPos;
		rxPosIndex=railTestData->m_RawData[i].m_Configurations.RawData.m_bRxPos;
		txIndex=matrixIndex(txRowIndex,txPosIndex,transRows,transPositions,1);
		rxIndex=matrixIndex(rxRowIndex,rxPosIndex,transRows,transPositions,1);
		railTestData->m_Working.m_RawSpectralData[i].m_Configurations.Spectral.m_couplingCorrection =
			transWeight[txIndex] * transWeight[rxIndex];
	}
}

void normaliseCouplingCoeffs(SingleRailTest *railTestData) {
	TRACE("Normalise coupling coefficents...\n");
	int numberTimeTraces=railTestData->m_RawData.GetSize();
	double mean=0.0;
	for (int i=0;i<numberTimeTraces;i++) {
		mean += railTestData->m_Working.m_RawSpectralData[i].m_Configurations.Spectral.m_couplingCorrection;
	}
	mean /= numberTimeTraces;
	if (mean<=0) {
		return;
	}
	for (i=0;i<numberTimeTraces;i++) {
		railTestData->m_Working.m_RawSpectralData[i].m_Configurations.Spectral.m_couplingCorrection /= mean;
	}
}

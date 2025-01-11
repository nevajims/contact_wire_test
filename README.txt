Usage
=====
Testing to see if I can commit and push from matlab. MJE 18/1/24
Unzip whole thing into folder and point matlab at this function:

[testdata, err] = GetDataFromDevice(cfg)

Param:
cfg: conforms to Test_Settings_1.mat

Returns:

testdata = 

  struct with fields:

     hash: '906 12-May-2023 08:35:26'
     test: {14×1 cell}
		14x2048 double		Tx channel 1
			14 rows of 2048 Rx1..14
		...
		14x2048 double
		14x1 double
		14x1 double
    dataz: [1×1 struct]
		freq	30x1 double
		z		14x30 double
		phi		14x30 double
		
Err
0	Success
1	Hashes don't match. Retrieved different file from that saved. e.g. Fails to save new data and returns previous file.
2	File not found (not saved at all)

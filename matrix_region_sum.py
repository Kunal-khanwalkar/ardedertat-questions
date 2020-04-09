def computeSum(arr):
	topRow, bottomRow = (0,len(arr)-1)
	leftCol, rightCol = (0,len(arr[0])-1)

	sums = [[0]*(rightCol-leftCol+1) for i in range(bottomRow-topRow+1)]
	sums[topRow][leftCol] = arr[topRow][leftCol]

	for col in range(leftCol+1,rightCol+1):									#Horizontal blocks
		sums[topRow][col] = sums[topRow][col-1] + arr[topRow][col]
	for row in range(topRow+1,bottomRow+1):									#Vertical blocks
		sums[row][leftCol] = sums[row-1][leftCol] + arr[row][leftCol]

	for col in range(leftCol+1,rightCol+1):
		columnSum = arr[topRow][col]
		for row in range(topRow+1,bottomRow+1):
			sums[row][col] = sums[row][col-1] + arr[row][col] + columnSum
			columnSum+=arr[row][col]

	return sums


def getSum(arr,A,D,sums):
	if len(arr)==0:
		return
	
	if A[0]==0 or A[1]==0:
		OA=0
	else:
		OA=sums[A[0]-1][A[1]-1]

	if A[1]==0:
		OC=0
	else:
		OC=sums[D[0]][A[1]-1]

	if A[0]==0:
		OB=0
	else:
		OB=sums[A[0]-1][D[1]]

	OD = sums[D[0]][D[1]]

	return OD-OB-OC+OA



if __name__=='__main__':
	arr = [ [1,2,3,4,5],
			[6,7,8,9,10],
			[11,12,13,14,15],
			[16,17,18,19,20],
			[21,22,23,24,25] ]		

	sums = computeSum(arr)	

	A = [2,1]
	D = [3,4]

	fsum = getSum(arr,A,D,sums)
	print(fsum)


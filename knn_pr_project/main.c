#define	 _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "struct.h"

/**************************
全局变量
***************************/
struct SAMPLE_ST* trainSet;
struct SAMPLE_ST* testSet;

/**************************
函数原型
***************************/
void	loadData(const char*, int, const char*, int);


int main() {
	int	i, j, label, errCnt = 0;
	struct SAMPLE_ST curTest;
	trainSet = (struct SAMPLE_ST*)calloc(TRAIN_CNT, sizeof(struct SAMPLE_ST));
	testSet = (struct SAMPLE_ST*)calloc(TEST_CNT, sizeof(struct SAMPLE_ST));

	// 加载训练和测试样本数据
	loadData(TRAIN_PATH, TRAIN_CNT, TEST_PATH, TEST_CNT);

	for (i = 0; i < TEST_CNT; i++)
	{
		curTest = testSet[i];

		label = knnClassifier(K, trainSet, TRAIN_CNT, curTest, CLASS_CNT, FEATURE_CNT);
		if (label != curTest.iClass)
		{
			printf("%d    ", i);
			errCnt++;
		}
	}
	printf("测试样本总数:%d, 错误个数:%d, 错误率:%lf \n", TEST_CNT, errCnt, errCnt / (TEST_CNT*1.0));

free(trainSet);
free(testSet);
	return 0;
}

/**************************
加载训练和测试样本
param trainSrc	训练样本文件路径
param trainCnt	训练样本个数
param testSrc	测试样本文件路径
param testCnt	测试样本文件路径
***************************/
void	loadData(const char* trainSrc, int trainCnt, const char* testSrc, int testCnt) {
	int	i, j;
	FILE	*fpTrain = NULL, *fpTest = NULL;

	if ((fpTrain = fopen(trainSrc, "r")) == NULL)
	{
		printf("open file \"%s failed! \n", trainSrc);
		exit(0);
	}

	// 加载训练样本
	for (i = 0; i < trainCnt; i++)
	{
		for (j = 0; j < FEATURE_CNT; j++)
		{
			fscanf(fpTrain, "%lf ", &trainSet[i].fv[j]);
		}
		fscanf(fpTrain, "%d", &trainSet[i].iClass);
		if (trainSet[i].iClass == -1)
		{
			trainSet[i].iClass = 0;
		}
	}

	if ((fpTest = fopen(testSrc, "r")) == NULL)
	{
		printf("open file \"%s failed! \n", testSrc);
		exit(0);
	}

	// 加载测试样本
	for (i = 0; i < testCnt; i++)
	{
		for (j = 0; j < FEATURE_CNT; j++)
		{
			fscanf(fpTest, "%lf ", &testSet[i].fv[j]);
		}
		fscanf(fpTest, "%d", &testSet[i].iClass);
		if (testSet[i].iClass == -1)
		{
			testSet[i].iClass = 0;
		}
	}

	fclose(fpTest);
	fclose(fpTrain);
}
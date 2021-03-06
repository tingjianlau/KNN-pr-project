#define	 _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**************************
不同场景下可能需修改的全局变量
***************************82852072 */
#define	K			7
#define	TRAIN_CNT		8285			// 训练样本数量
#define	TRAIN_PATH	"train.data"	// 训练样本文件路径
#define	TEST_CNT		2072			// 测试样本数量
#define TEST_PATH	"test.data"		// 测试样本文件路径
#define	CLASS_CNT	3				// 样本类别种数
#define	FEATURE_CNT	10				// 单个样本特征数

/**************************
全局结构
***************************/
struct SAMPLE_ST {
	double	fv[FEATURE_CNT];
	int		iClass;
};

int knnClassifier(int, struct SAMPLE_ST*, int, struct SAMPLE_ST, int, int);
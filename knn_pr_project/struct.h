#define	 _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**************************
��ͬ�����¿������޸ĵ�ȫ�ֱ���
***************************82852072 */
#define	K			7
#define	TRAIN_CNT		8285			// ѵ����������
#define	TRAIN_PATH	"train.data"	// ѵ�������ļ�·��
#define	TEST_CNT		2072			// ������������
#define TEST_PATH	"test.data"		// ���������ļ�·��
#define	CLASS_CNT	3				// �����������
#define	FEATURE_CNT	10				// ��������������

/**************************
ȫ�ֽṹ
***************************/
struct SAMPLE_ST {
	double	fv[FEATURE_CNT];
	int		iClass;
};

int knnClassifier(int, struct SAMPLE_ST*, int, struct SAMPLE_ST, int, int);
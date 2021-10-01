#include <stdio.h>

#define VERTEX 5  // ������ ����
#define MAX_DEGREE 2  // ������ ����� �� �ִ� ������ �ִ� ����
#define ALREADY_PASSED -1

int isGraphAllPassed(int graph[VERTEX][MAX_DEGREE]);

int main(void)
{
    // �������� 5���̰� �� �������� ���� 2���� �׷���
    // (= �ִ� ������ 2�� ���� 5���� ���� �׷���)
    int graph[VERTEX][MAX_DEGREE] = {
        {3, 4},  // 0 - [3, 4]
        {2, 4},  // 1 - [2, 4]
        {1, 3},  // 2 - [1, 3]
        {0, 2},  // 3 - [0, 2]
        {0, 1}   // 4 - [0, 1]
    };

    int moveTo;
    int current_vertix = 0;  // ���� ��ġ�� ������ ����Ű�� ����
    int isAbleToDraw = 0;  // �׷����� ��� ������ ������������ ���θ� �����ϴ� ����

    for (int i=0; i<VERTEX*MAX_DEGREE; i++)
    {
        printf("current_vertix = %d\n", current_vertix);
        for (int j=0; j<MAX_DEGREE; j++)
        {
            // ���� ������ ������ �ʾҴٸ�
            // �ش� ������ ���� �ٸ� �������� �̵�
            if (graph[current_vertix][j] != ALREADY_PASSED)
            {
                moveTo = graph[current_vertix][j];
                graph[current_vertix][j] = ALREADY_PASSED;

                // �̵��� ���������� �ߺ��� ���� ���� ����
                for (int k=0; k<MAX_DEGREE; k++)
                {
                    if (graph[moveTo][k] == current_vertix)
                        graph[moveTo][k] = ALREADY_PASSED;
                }
                current_vertix = moveTo;
                break;
            }
        }

        if (isGraphAllPassed(graph))
        {
            isAbleToDraw = 1;
            break;
        }
    }

    printf("�� �׷����� �Ѻױ׸��Ⱑ %s�� �����Դϴ�.\n", (isAbleToDraw == 1) ? "����" : "�Ұ���");
    
    return 0;
}

// ��� ������ �� ���������� �˻��ϴ� �Լ� (�� �������� 1, �ƴϸ� 0�� ��ȯ)
int isGraphAllPassed(int graph[VERTEX][MAX_DEGREE])
{
    for (int i=0; i<VERTEX; i++)
    {
        for (int j=0; j<MAX_DEGREE; j++)
        {
            if (graph[i][j] != ALREADY_PASSED)
                return 0;
        }
    }
    return 1;
}

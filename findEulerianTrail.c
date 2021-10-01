#include <stdio.h>

#define VERTEX 5  // 정점의 개수
#define MAX_DEGREE 2  // 정점에 연결될 수 있는 간선의 최대 개수
#define ALREADY_PASSED -1

int isGraphAllPassed(int graph[VERTEX][MAX_DEGREE]);

int main(void)
{
    // 꼭짓점이 5개이고 각 꼭짓점의 변이 2개인 그래프
    // (= 최대 차수가 2인 정점 5개를 가진 그래프)
    int graph[VERTEX][MAX_DEGREE] = {
        {3, 4},  // 0 - [3, 4]
        {2, 4},  // 1 - [2, 4]
        {1, 3},  // 2 - [1, 3]
        {0, 2},  // 3 - [0, 2]
        {0, 1}   // 4 - [0, 1]
    };

    int moveTo;
    int current_vertix = 0;  // 현재 위치한 정점을 가리키는 변수
    int isAbleToDraw = 0;  // 그래프의 모든 간선을 지나갔는지의 여부를 저장하는 변수

    for (int i=0; i<VERTEX*MAX_DEGREE; i++)
    {
        printf("current_vertix = %d\n", current_vertix);
        for (int j=0; j<MAX_DEGREE; j++)
        {
            // 만약 간선을 지나지 않았다면
            // 해당 간선을 통해 다른 정점으로 이동
            if (graph[current_vertix][j] != ALREADY_PASSED)
            {
                moveTo = graph[current_vertix][j];
                graph[current_vertix][j] = ALREADY_PASSED;

                // 이동한 정점에서의 중복된 간선 또한 제거
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

    printf("이 그래프는 한붓그리기가 %s한 도형입니다.\n", (isAbleToDraw == 1) ? "가능" : "불가능");
    
    return 0;
}

// 모든 간선을 다 지났는지를 검사하는 함수 (다 지났으면 1, 아니면 0을 반환)
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

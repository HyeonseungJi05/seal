# include <iostream>
# include <queue>
# include <cmath>

int main()
{
    //입력
    int tc = 0;
    std::cin >> tc;
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

    int sumNum = 0; // 합

    for(int i = 0; i < tc; i++)
    {
        int a;
        std::cin >> a;
        pq.push(a);
        sumNum += a;
    }

    int top = 0;
    int topSaved = 0;

    int maxNum = 0; // 최대값
    int minNum = pq.top(); // 최소값

    int maxJungbok = 0;
    int maxJungbokNum = -1; // 최반값
    int lastJungbok = 0;
    bool alreadyCheck = false;

    int midNum = 0; // 중간값

    int pqSize = pq.size();

    for(int i = 0; i < pqSize; i++)
    {
        top = pq.top();
        if(i == tc/2)
        {
            midNum = top;
        }

        if(i == 0 || (i == 1 && topSaved != top))
        {
            maxJungbokNum = top;
            topSaved = top;
            pq.pop();
            continue;
        }

        if(topSaved == top) {
            ++lastJungbok;
        }

        else {
            //중복 횟수가 동일한 경우 1회에 한하여
            if(maxJungbok == lastJungbok && !alreadyCheck) {
                maxJungbokNum = topSaved;
                alreadyCheck = true;
            }
            //중복횟수가 많은경우
            if(maxJungbok < lastJungbok) {
                maxJungbok = lastJungbok;
                maxJungbokNum = topSaved;
                alreadyCheck = false;
            }

            lastJungbok = 0;
        }
        topSaved = top;

        pq.pop();
    }

    if(maxJungbok == lastJungbok && !alreadyCheck) {
        maxJungbokNum = topSaved;
        alreadyCheck = true;
    }
    //중복횟수가 많은경우
    if(maxJungbok < lastJungbok) {
        maxJungbok = lastJungbok;
        maxJungbokNum = topSaved;
        alreadyCheck = false;
    }

    maxNum = top;

    int res01 = round(sumNum / (float)pqSize); //산술평균
    int res02 = midNum; // 중앙값
    int res03 = maxJungbokNum; // 최빈값
    int res04 = maxNum - minNum; // 범위

    std::cout << res01 << std::endl;
    std::cout << res02 << std::endl;
    std::cout << res03 << std::endl;
    std::cout << res04 << std::endl;


    return 0;

}
//
//  main.c
//  图的深度优先遍历(有向图)
//
//  Created by Cass on 2017/4/10.
//  Copyright © 2017年 cass. All rights reserved.
//

#include <stdio.h>
int min = 9999999, book[101], n, e[101][101];

//cur 是当前所在城市编号，dis 是当前已经走过的路程
void dfs (int cur, int dis) {
    int j;
    
    //如果当前走过的路程已经大于之前找到的最短路径，立即返回
    if (dis > min) return;
    if (cur == n) {
        if (dis < min) min = dis; //更新最小值
        return;
    }
    
    for (j = 1; j <= n; j++) {
        //判断当前城市 cur 到城市 j 是否有路，并判断城市 j 是否在已走过的路径中
        if (e[cur][j] != min && book[j] == 0) {
            book[j] = 1;//标记城市 j 已在路径中
            dfs(j, dis + e[cur][j]); //从城市 j 再出发，继续寻找目标城市
            book[j] = 0; //之前一步探索完毕以后，取消对城市 j 的标记
        }
    }
    return;
}


int main(int argc, const char * argv[]) {
    
    int i, j, m, a, b, c;
    scanf("%d   %d",&n,&m);
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = min;
            }
        }
    }
    
    //读入城市之间的道路
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d",&a, &b, &c);
        e[a][b] = c;
    }
    
    book[1] = 1;
    dfs(1, 0);
    printf("%d\n",min);
    
    
    return 0;
}

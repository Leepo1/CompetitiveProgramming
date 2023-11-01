import collections
dx = [1,-1,0,0]
dy = [0,0,1,-1]
def solution(grid):
    walls = []
    r = len(grid)
    c = len(grid[0])
    ans = r*c
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if(grid[i][j]==1):
                walls.append((i,j))

    for x,y in walls:
        grid[x][y] = 0   
        # BFS from 0 and determine dist to end if reached
        q = collections.deque()
        dist = [[-1 for i in range(c)] for j in range(r)]
        dist[0][0]=1    
        q.append((0,0))
        while len(q)!=0:
            px,py = q.popleft()
            if px == r-1 and py == c - 1:
                ans = min(ans,dist[px][py])
                break
            for d in range(4):
                nx = px + dx[d]
                ny = py + dy[d] 
                if 0<=nx<r and 0<=ny<c:
                    if dist[nx][ny]!=-1:
                        continue
                    if grid[nx][ny]==1:
                        continue
                    dist[nx][ny] = dist[px][py] + 1
                    q.append((nx,ny))
        #
        grid[x][y] = 1
    return ans


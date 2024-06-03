/*
prim(graph, V, x, y) // If u,v belongs to graph then skip it
    visited
    pq = {}
    pq.push(1,0)
    while(!pq.empty)
        u = qq.pop()
        visited[u] = true
        for(v, u in graph[u)
            if(u = x, v = y OR u = y, v = x)
                continue
            if(!visited[v] && dist[v] > w)
                dist[v] = w
                pq.push(v,w)
                path[v] = u
    res = 0
    for i from 2 -> V
        if(!visited[i])
            -> INF
        res += dist[i]
    return res

Tim MST
Lay canh MST edges
MST2 = INF
for(u, v) in edges
    MST2 = min(MST2, prim(graph, V, u, v))
*/
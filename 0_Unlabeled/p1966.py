#효서 제출

testnum = int(input())
for ii in range(testnum):
    num_max = 0
    num , wfile = map(int, input().split(' '))
    files = list(map(int, input().split(' ')))

    for nn in files:
        if nn > num_max:
            num_max = nn
            break

    pnum = 0
    while(len(files)):
        if files[0] < num_max: #넘기기
            files.append(files[0])
            del files[0]
            wfile -= 1
            if wfile == 0:
                wfile = len(files)-1
        
        if files[0] == num_max: #인쇄
            pnum += 1
            del files[0]
            num_max = 0
            for nn in files:
                if nn > num_max:
                    num_max = nn
                    break
            if wfile == 0:
                break
            wfile -= 1


    print(pnum)
        

    
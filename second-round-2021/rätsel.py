for i in range(1000):
    for j in range(1000):
        inumber = [int(iss) for iss in str(i)]
        jnumber = [int(iss) for iss in str(j)]
        if(i+j)/2 == 555 and i/(sum(inumber)) == 49 and j/sum(jnumber) == 25 and jnumber[0] == inumber[1] åand jnumber[1] == inumber[0]:
            print(i,j) 

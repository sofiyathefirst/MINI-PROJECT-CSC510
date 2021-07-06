int main()
{
    enum{S0, S1, S2, S3, S4, Sstop} state;
    char input;

    state = S0;
    while(state != Sstop)
    {
        switch(state)
        {
            case S0:
            if(input == 'a') {state = S1;}
            break;
            case S1:
            if(input == 'b') {state = S3;}
            break;
            case S2:
            if(input == 'a') {state = S3;}
            if(input == 'b') {state = S4;}
            break;
            case S3:
            if(input == 'a') {state = S4;}
            break;
        }
    }
    return 0;
}
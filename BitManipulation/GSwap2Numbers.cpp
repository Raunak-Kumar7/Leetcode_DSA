//method 1:
    pair<int, int> get(int a, int b){
        int temp = a;
        a=b;
        b=temp;
        return {a,b};
    }


//method 2:
    pair<int, int> get(int a, int b){
        swap(a,b);
        return {a,b};
    }

//////////IMPORTANT///////////
//method 3: without 3rd variable
    pair<int, int> get(int a, int b){
        a = a+b;
        b = a-b;
        a = a-b;
        return {a,b};
    }

//We can also use */ instead of +-, But it can cause integer overflow, */ doesnt work for 0(a or b)
// similarly it can be done using ^


//method 4: without 3rd variable
    pair<int, int> get(int a, int b){
        a = a^b;
        b = a^b;
        a = a^b;
        return {a,b};
    }
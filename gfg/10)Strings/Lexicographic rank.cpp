
//5) Given a string, find its lexicographic rank of it.
//->Naive approach is considering all permutations of string which exponential time in worst case
void naiveLexographicRank(string str){          //*** works for duplicate characters as well ****
    int rank = 1;
    string temp = str;
    sort(temp.begin(), temp.end());
    while(next_permutation(temp.begin(), temp.end())){
        ++rank;
        if(temp == str) break;
        //cout<<temp<<", ";
    }
    cout<<endl<<"Rank: "<<rank;
}

//->Do it in linear time, we have to use a mathematical formula: **RR**
//*** does not work for duplicate characters ****
long long int fact(int n){
    long long int result = 1;
    while(n>0){
        result *= n;
        --n;
    }
    return result;
}

int linearTimeLexographicRank(string str){          //*** does not work for duplicate characters ****
    int count[256] = {0};
    for(int i=0;i<str.size();++i){
        if(count[str[i]] == 0) count[str[i]]++;
        else return -1;                             //rank is -1 when there are duplicate characters present, coz this algo doesn't work when there are duplicate characters
    }
    for(int i=1;i<256;++i) count[i] += count[i-1];
    
    long long int f = fact(str.size());
    
    int rank = 1; //formula requires 1 to be added
    for(int i=0;i<str.size();++i){
        f /= (str.size()-i);
        rank += (count[str[i]-1] * f);
        for(int j = str[i];j<256;++j) --count[j];
    }
    
    cout<<"Lexicographic Rank: "<<rank;
}

int main() {
    string str = "string";
    linearTimeLexographicRank(str);
}
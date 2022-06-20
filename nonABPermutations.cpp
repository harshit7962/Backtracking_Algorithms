/**
Given a string, we need to print all the permutations of that string which do not contain "AB" as its substring
*/

void permutations(string str, string curr="") {
    if(str.size()==0) {
        cout << curr << " "; 
        return;
    }
    
    for(int i=0;i<str.size();i++) {
        //Here, we stop the process of adding AB containing substring as soon as it is encountered to decrease unnecessary computations...
        if(!(str[i]=='B' && curr[curr.size()-1]=='A')) {
            string nextstr = str.substr(0, i) + str.substr(i+1);
            permutations(nextstr, curr+str[i]);
        }
    }
}

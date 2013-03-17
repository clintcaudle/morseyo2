#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

void morse (char ascval);

char chardata[] = { 18, 00, 00, 00, 00, 30, 45,
    
    45, 00, 00, 51, 33, 42, 9, 31, 30, 28,
    
    24, 16, 0, 1, 3, 7, 15, 7, 00, 00,
    
    17, 00, 12, 22, 2, 1, 5, 1, 0, 4,
    
    3, 0, 0, 14, 5, 2, 3, 1, 7, 6,
    
    11, 2, 0, 1, 4, 8, 6, 9, 13, 3
    
};

char sizedata[] = { 6, 00, 00, 00, 00, 6, 6,
    
    6, 00, 00, 6, 6, 6, 5, 5, 5, 5,
    
    5, 5, 5, 5, 5, 5, 5, 6, 00, 00,
    
    5, 00, 6, 6, 2, 4, 4, 3, 1, 4,
    
    3, 4, 2, 4, 3, 4, 2, 2, 3, 4,
    
    4, 3, 3, 1, 3, 4, 3, 4, 4, 4
    
};



void morse(char ascval)

{
    
    char code, bits;
    
    bits = 0;
    
    if (ascval == 32) {
        
        cout << " ";
        
        return;
        
    }
    
    if (ascval > 33 && ascval < 91) {
        
        code = chardata[ascval - 34];
        bits = sizedata[ascval - 34];
        
    }
    
    for (int i = 1; i <= bits; i++) {
        
        if (code % 2) {
            
            cout << "-";
            
        } else {
            
            cout << ".";
            
        }
        
        code = code >> 1;
        
    }
    
    if (bits) {
        
        cout << "/";
        
    }
    return;
}



int main()

{
    
    string str;
    cout<<"Enter the string of code to translate to Morse:"<<endl;
    
    while(getline(cin, str)){;
    if (str == "exit"){
        break;   
    }
        
        
    //Make Upper Case
    transform(str.begin(), str.end(), str.begin(), (int (*)(int)) toupper);
    
    for (int i = 0; i <= str.length() - 1; i++) {
        
        morse(str[i]);

    }
        cout<<endl;
    }
    
    return 0;
    
}

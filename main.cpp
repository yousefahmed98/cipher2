#include<bits/stdc++.h>

using namespace std;
string Int_to_Str( int x );
string decimal_to_binary( int num );
string small_to_capital(string P);
string string_to_string( string E );
string string_to_binary(string x);
//---------------------------------------------------
//7. Morse Code
struct Pairs
{
    char Letter;
    string Pattern;
};
void CheckPattern(Pairs pr[],string temp);
void CheckLetter(Pairs pr[],char c);
//------------------------------------------------------
//9. Rail-fence Cipher
void CheckPattern(Pairs pr[],string temp);
string encryptrailfence(string text,int key);
string decryptrailFence(string cipher, int key);



int main()
{

    //-------------------------------------------------------------------------------------------------------------
    int z;
    cout<<"0. Affine Cipher"<<endl<<"1. Caesar Cipher"<<endl<<"2. Atbash Cipher"<<endl
        <<"3. ROT13 Cipher"<<endl<<"4. Baconian Cipher"<<endl<<"5. Simple Substitution Cipher."<<endl<<"6. Polybius Square Cipher"
        <<endl<<"7. Morse Code"<<endl<<"8. XOR Cipher"<<endl<<"9. Rail-fence Cipher"<<endl<< "Enter the encryption number ";
    cin>>z;

//-------------------------------------------------------------------------------------------------------------
//0. Affine Cipher
if(z==0)
{
        char letters[26]= {'A','B','C','D','E','F','G','H', 'I','J', 'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        string message;
        string word;
        int a,b,c;
        cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
        cin.ignore();
        getline(cin,word);
        cout<<"enter the message"<<endl;
        getline(cin,message);

        cout<<"Enter parameters a,b and c"<<endl;
        cout<<"parameter1 is:";
        cin>>a;
        cout<<"parameter2 is";
        cin>>b;
        cout<<"parameter3 is";
        cin>>c;
        while ((a*c)%26!=1)
        {
            cout<<" Enter another parameters"<<endl;
            cout<<"parameter1 is:";
            cin>>a;
            cout<<"parameter2 is";
            cin>>b;
            cout<<"parameter3 is";
            cin>>c;
        }


        for (int k=0; k<message.length(); k++)
        {
            message[k]=toupper(message[k]);
        }

        for(int i=0; i< message.length() ; i++)
        {
            for(int j=0; j<26; j++)
            {
                if(message[i]==' ')
                {
                    cout<<char(32);
                    break;
                }
                else if (word=="2" && message[i]==letters[j])
                {
                    int z=c*(j-3)%26;
                    cout <<letters[z];
                    break;

                }


                else if (word=="1" && message [i]==letters[j])
                {
                    int z=((a*j)+3)%26;
                    cout<<letters[z];
                    break;

                }

            }



        }



        return 0;
    }
//--------------------------------------------------------------------------------------------------------------------------
//1. Caesar Cipher
if(z==1)
{

    string  W , message = "" , cipher = "";
    int x = 0 , steps = 0;
    char letter;

    cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
    cin >> W ;
    cin.ignore() ;
    if ( W== "1" || W=="2" )
    {

    cout << "Enter Message : " ;

    getline( cin , message );

    cout << "Enter Number Of Steps : ";
    cin  >> steps;
    cin.ignore();

	steps %= 26;
    }

        { steps *= -1;}

    for ( int i = 0; i < message.length(); i++ ){
        letter = message[i];
        x  = ( int )letter;
        if ( x >= 65 && x <= 90 ){
            x += steps;
            if ( x > 90){ x -= 26; }
            else if ( x < 65 ){ x += 26; }
        }
        else if ( x >= 97 && x <= 122 ){
            x += steps;
            if ( x  > 122 ){ x -= 26; }
            else if ( x < 97 ){ x += 26; }
        }
         cipher += (char)x;

    }
   if (W=="3")
   {
       cout << "END THE PROGRAM" ;
       return 0;
   }
    cout << "Cipher Message is  :  " << cipher << endl ;
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------
//2. Atbash Cipher
if(z==2)
{
    string message ;
    int x;
   cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
    cin>>x;
    cin.ignore();
    if(x==1||x==2)
    {
        cout << "Enter your message " ;
        getline( cin, message ) ;
        for ( int i=0 ; i <= message.length() ; i++)
        {
            if ( message[i] >= 65 && message[i] <= 90 )
            {
                message[i]+=(25-(2*(message[i]-65))) ;
            }
            if ( message[i] >= 97 && message[i] <= 122 )
            {
                message[i]+=(25-(2*(message[i]-97))) ;
            }


        }
        cout << message ;
        return 0;
    }
    else
    {
        cout << "you Ending the Program" ;
        return 0;
    }


}
//----------------------------------------------------------------------------------------------------------------------------------
//3. ROT13 Cipher
if(z==3)
    {

    string message;
    int x;

    cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
    cin >> x;
    cin.ignore();

    if (x==1)
    {
        cout << "Enter the message : ";

        getline(cin,message);

        for ( int i=0 ; i<=message.length() ; i++)
            {
            if ( (message [i] >= 'a' && message [i] < 'n') || (message [i] >= 'A' && message [i] < 'N'))
            {
                message[i]+=13;
            }
            else if ( (message [i] >= 'n' && message [i] <= 'z' ) || (message [i] >= 'N' && message [i] <= 'Z'))
                {
                    message[i]-=13;
                }
            }
        cout << message << endl;
        }


    else if (x==2)
    {
        cout << "Enter the message :";

        getline(cin,message);

        for ( int i=0 ; i<=message.length() ; i++)
            {
            if ( (message [i] >= 'a' && message [i] < 'n') || (message [i] >= 'A' && message [i] < 'N'))
            {
                message[i]+=13;
            }
            else if ( (message [i] >= 'n' && message [i] <= 'z' ) || (message [i] >= 'N' && message [i] <= 'Z'))
                {
                    message[i]-=13;
                }

            }
      cout << message << endl;
      }
    else
    {
        cout << "END THE PROGRAM" << endl;
    }

    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------
//4. Baconian Cipher
if(z==4)
{

    string ask ="";
   cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
    cin  >> ask;


    int ascci = 0;
    string conv = "" , result = "";

    if ( ask == "1" ){
        cout<<" Enter Your Message: ";
        string cipher = "";
        cin.ignore();
        getline( cin , cipher );

        cipher = small_to_capital( cipher );

        for ( int i = 0; i < cipher.length(); i++ ){

            ascci = (int)cipher[i];

                conv = decimal_to_binary( ascci );
                conv = string_to_string( conv );
                result += conv;




        }
        cout << result << endl;

    }
    else {

        string message ="";
        cout <<"enter your message: "<< endl;
        cin.ignore();
        getline( cin , message );
        for ( int i = 0; i < message.length(); i++){
            if ( message[i]== 'a' ){
                message[i]= '0';
            }
            else if( message[i]== 'b'){
                message[i]='1';
            }
        }
        string txt = ""; int ascci = 0;
        for ( int i = 0; i < message.length(); i += 8 ){
            txt = "";

            for ( int j = 0; j < 8; j++ ){ txt += message[i+j]; }

        int counter = 0;
        int num = 0;
        int sum = 0;


        for(int i = 7; i > -1 ; i--){

            if (txt[i] == '1'){
                num=1;
            }
            else{num = 0;}
            sum += num*pow(2,counter);
            counter++;

        }

        result += (char)sum;

        }

        cout << result;

    }


    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------
//5. Simple Substitution Cipher.

if(z==5)
{
        int x,num=0;
        cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
        cin >> x;

        string text,cipher,temp,key,alpha="abcdefghijklmnopqrstuvwxyz";
        if(x==3)
        {
            return 0;
        }
        cout<< "key :";
        cin>>key;
        cout<< "text :";
        cin.ignore();
        getline(cin,text);
        for(int i=0; i<26; i++)
        {
            if(key[0]!=alpha[i]&&key[1]!=alpha[i]&&key[2]!=alpha[i]&&key[3]!=alpha[i]&&key[4]!=alpha[i])
            {
                temp+=alpha[i];

            }
        }
        cipher=key+temp;

        if(x==1)
        {
            for (int i=0; i<text.length(); i++)
            {
                if(text[i]==' ')
                {
                    text[i]=' ';
                }
                else
                {
                    text[i]=cipher[text[i]-'a'];
                }
            }
        }
        if(x==2)
        {
            for (int i=0; i<text.length(); i++)
            {
                num=0;

                for(int j=0; j<26; j++)
                {

                    if(cipher[j]==text[i])
                    {
                        break;
                    }
                    num++;

                }
                text[i]=alpha[num];
            }
        }
        cout<<text<<endl;
      return 0;


}
//---------------------------------------------------------------------------------------------------------------------------------
//6. Polybius Square Cipher
if(z==6)
{
    int x,num=0;
    cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
    cin >> x;
    if(x==3)
    {
        return 0;
    }
    if(x==1)
    {

    string secretkey,space ;
    string alpha;
    space=" ";
    alpha="abcdefghigklmnopqrstuvxyz";
    cout<<"secret key from 5 numbers:";
    cin>>secretkey ;
    cin.ignore() ;
    cout<<"text :";
    string textmsg ;
    getline(cin,textmsg);

    for(int i=0 ; i<textmsg.size(); i++)
    {
        int pos1=0,pos2=0;
            if(textmsg[i]==space[0])
            {
                cout<<" ";
            }
        for(int j=0; j<25; j++)
        {

            if(textmsg[i]==alpha[j])
            {
                cout<<secretkey[pos1]<<secretkey[pos2];
            }
            pos2+=1;
            if(pos2==5)
            {
                pos1+=1;
                pos2=0;
            }
            if(pos1==5)
                pos2=0;
        }

    }
     return 0;


}

if(x==2)
{
    string alpha2[5][5];
    alpha2[0][0]='a';alpha2[0][1]='b';alpha2[0][2]='c';alpha2[0][3]='d';alpha2[0][4]='e';alpha2[1][0]='f';alpha2[1][1]='g';alpha2[1][2]='h';alpha2[1][3]='i';alpha2[1][4]='j';alpha2[2][0]='k';alpha2[2][1]='l';alpha2[2][2]='m';alpha2[2][3]='n';alpha2[2][4]='o';alpha2[3][0]='p';alpha2[3][1]='q';alpha2[3][2]='r';alpha2[3][3]='s';alpha2[3][4]='t';alpha2[4][0]='u';alpha2[4][1]='v';alpha2[4][2]='x';alpha2[4][3]='y';alpha2[4][4]='z';
    string text,key;
    cout<<"text :";
    cin.ignore();
    getline(cin,text);

    cout<<"enter the key from 5 num:";
    cin>>key;
    cin.ignore();
    for(int i=0;i<text.size();i+=2)
    {
        int pos1=0,pos2=0;
        for(int j=0;j<key.size();j++)
        {
            if(text[i]==' ')
            {
                cout<<' ';
                i++;
                break;
            }
            if(text[i]==key[j])
            {
                break;
            }
            pos1+=1;

        }
        for(int l=0;l<key.size();l++)
        {
            if(text[i+1]==key[l])
            {
                break;
            }
            pos2+=1;

        }
        if(text[i]!=' ')cout<<alpha2[pos1][pos2];
    }
}
}
//------------------------------------------------------------------------------------------------------------------------
//7. Morse Code
if(z==7)
{
    Pairs pr[]= {{'a',".-"},{'b',"-..."},{'c',"-.-."},{'d',"-.."},{'e',"."},{'f',"..-."},{'g',"--."},{'h',"...."},{'i',".."},{'j',".---"},{'k',"-.-"},{'l',".-.."},{'m',"--"},{'n',"-."},{'o',"---"},{'p',".--."},{'q',"--.-"},{'r',".-."},{'s',"..."},{'t',"-"},{'u',"..-"},{'v',"...-"},{'w',".--"},{'x',"-..-"},{'y',"-.--"},{'z',"--.."},{' '," "}};

    int ch;
   cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
    cin >> ch;
    while (true)
    {
        if (ch > 3)
            {
            cout << "Invalid choice!\nPlease choose another choice" << endl;
            cin >> ch;
            }else{
                break;
                }
    }

    if(ch==1)
    {
        string text;
        cout << "Please enter the text you want to cipher:" << endl;
        cin.ignore();
        getline(cin,text);

        for(int i=0;i<text.size();i++)
        {
            char c = tolower(text[i]);
            CheckLetter(pr,c);

        }

    }
    else if(ch==2)
    {
        string pattern="";
        cout << "Please enter the text you want to decipher:" << endl;
        cin.ignore();
        getline(cin,pattern);
        pattern=pattern+' ';
        string temp ="";
        for(int i=0;i<pattern.size();i++)
        {

            if(pattern[i] == ' ')
            {
                CheckPattern(pr,temp);

                temp = "";
                   if(i != pattern.size()-1)
                {
                    if(pattern[i+1]== ' ' && pattern[i+2]== ' ')
                    {
                         // i++;
                        cout << " ";
                    }
                }


                  continue;
            }

        temp+=pattern[i];


        }

    }
    else if(ch==3){



    return 0;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------
//8. XOR Cipher
if(z==8)
{
    string text="" ;
    int i ,z=0 ;
    char key ;
    int y = 0;

   cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
    cin >> z ;

    cout << "Enter a secret letter: ";
    cin>> key ;

    cin.ignore();

    if(z==1){
        cout <<"Enter Sentence: " ;

        getline(cin,text);

        cout << " Message is: " ;

        for (i=0 ; i < text.length() ; i++)
        {
            y = (int)text[i] ^ (int)key ;
            text[i] = (char)y ;

            if ( y <= 15 ) { cout << "0"; }
            cout << hex << y ;
        }
        cout << endl;

        cout << " Message is : " << text;
    }

    if (z==2)
    {
        cout <<"Enter Ciphered Sentence: " ;

        getline(cin,text);

        for (i=0 ; i < text.length() ; i++)
        {
            y = text[i] ^ key ;
            text[i] = (char)y ;

        }
        cout << "Decipherd message is: " << text ;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------
//9. Rail-fence Cipher
if(z==9)
    {
    cout<< "enter 1 to Encryption and 2 to Decryption and 3 to end : ";
    int ch;
    cin >> ch;
    if(ch==1){
    string text;
    int key;
    cout<<"enter text: "<<endl;
    cin>> text;
    cout<<"enter key: "<<endl;
    cin>>key;
    cout<<encryptrailfence(text,key)<<endl;
    }
    else if (ch==2){
    string cipher;
    int key;
    cout<<"enter cipher: "<<endl;
    cin>> cipher;
    cout<<"enter key: "<<endl;
    cin>>key;
    cout<<encryptrailfence(cipher,key)<<endl;

    }
    if (ch==3)
        cout<<"goodbye"<<endl;

}


}
//------------------------------------------------------------
//4. Baconian Cipher

string Int_to_Str( int x ){
    string num = "";
    if ( x == 1 ){ num = "1"; }
    else{ num = "0"; }
    return num;
}

string decimal_to_binary( int num ){
    int mod = 0;
    string binary = "";
    while(num != 0){
      mod = num % 2;
      num = num / 2;
      binary = Int_to_Str( mod ) + binary;
    }

    for ( int i = binary.length(); i < 8; i++ ){
        binary = "0" + binary;
    }

    return binary;
}

string small_to_capital(string P){
    int ascci = 0;
    for ( int i = 0; i < P.length() ; i++){
        ascci = (int)P[i];
        if ( ascci >= 97 and ascci <= 122 ){ ascci -= 32; }
        P[i] = (char)ascci;
    }
    return P;
}

string string_to_string( string E ){
    for ( int i = 0; i < 8; i++){
        if ( E[i]=='0'){
            E[i]='a';
        }
        else{
            E[i]='b';

        }
    }
    return E;
}

string string_to_binary(string x){
    for ( int i = 0; i < 8; i++){
        if ( x[i]=='a'){
            x[i]='0';
        }
        else{
            x[i]='1';

        }
    }
    return x;
}
//-----------------------------------------------
//7. Morse Code
void CheckLetter(Pairs pr[],char c)
{
    for(int k=0;k<26;k++)
    {
        if(c==pr[k].Letter)
        {
            cout << pr[k].Pattern << " " ;
        }
    }
}

void CheckPattern(Pairs pr[],string temp)
{

    for(int j=0;j<26;j++)
    {
       if(temp==pr[j].Pattern)
        {
           cout << pr[j].Letter;
        }
    }
}
//-------------------------------------------------
//9. Rail-fence Cipher
string encryptrailfence(string text,int key)
{
    char rail[key][(text.length())];
    for(int i=0;i<key;i++)
        for(int j=0;j<text.length();j++)
            rail[i][j]='\n';
     bool dir_down=false;
     int row=0, col=0;
     for(int i=0;i<text.length();i++)
     {
         if(row==0 || row==key-1)
            dir_down= !dir_down;
         rail[row][col++]=text[i];
         dir_down?row++ : row--;
     }
     string result;
     for(int i=0;i<key;i++)
        for(int j=0;j<text.length();j++)
               if(rail[i][j]!='\n')
                  result.push_back(rail[i][j]);
     return result;
}
string decryptrailFence(string cipher, int key)
{
    char rail[key][cipher.length()];
    for(int i=0;i<key;i++)
        for(int j=0;j<cipher.length();j++)
            rail[i][j]='\n';
    bool dir_down= false;
    int row=0, col=0;
    for(int i=0;i<cipher.length();i++)
    {
        if(row==0)
          dir_down= true;
        if(row==key-1)
            dir_down= false;
        rail[row][col++]= '*';
        dir_down?row++ : row--;
    }
    int index=0;
    for(int i=0;i<key;i++)
        for(int j=0;j<cipher.length();j++)
            if(rail[i][j]== '*' &&index<<cipher.length())
               rail[i][j]= cipher[index++];
    string result;
    row =0, col=0;
    for(int i=0;i<cipher.length();i++)
    {
        if(row==0)
            dir_down= true;
        if(row==key-1)
            dir_down= false;
        if(rail[row][col] !='*')
            result.push_back(rail[row][col++]);
        dir_down?row++ : row--;
    }
    return result;
}

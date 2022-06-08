#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include <locale.h>
#include <windows.h>
using namespace std;
void uzu(int p[10][10])//funkcja ktora ustawia 4 masztowiec dla komputera.
{
    int w,k,c=1,kierunek,i;
    //cztero
    //1gora 2dol 3prawo 4lewo
    bool pra=true,lew=true,gor=true,dol=true;
    w=rand()%10;//losuje wiersz i kolumne
    k=rand()%10;
    if(w<=3)//sprawdzam czy statek sie zmieści czy nie
    {gor=false;
    }
    if(w>=6)
        dol=false;
    if(k>=6)
        pra=false;
    if(k<=3)
        lew=false;
    while(c==1)//czeka az rostanie postawiony 4 masztowiec tak dlugo sie bedzie wykonywac
      {kierunek=rand()%3;//losuje jeden z kierunkow
      if(kierunek==0 and gor==true)//sprawdza czy wylosowany kierunek to w góre i czy jest tam miejsce
      {
          for(i=0;i<6;i++)
          {if(w==9 and i==0)
            i=1;
            if(w==3 and i==5)
                break;
            if(i>0 and i<5)
             {
                 p[w-i+1][k]=4;//stawia statek
             }
             else
                {if(w!=0)
                    p[w-i+1][k]=-1;}
             if(k!=9 )
             p[w-i+1][k+1]=-1;
            if(k!=0)
            p[w-i+1][k-1]=-1;}//stawia -1 wokol statku
            c=0;

        }
     if(kierunek==1 and dol==true)//sprawdza czy wylosowany kierunek to w dół i czy jest tam miejsce

        {
          for(i=0;i<6;i++)
          {     if(w==0 and i==0)
        i=1;

      if(w==6 and i==5)
           break;
              if(i>0 and i<5)
             {
              p[w+i-1][k]=4;
             }
             else
                p[w+i-1][k]=-1;
            if(k!=9 )
             p[w+i-1][k+1]=-1;
            if(k!=0)
            p[w+i-1][k-1]=-1;}
            c=0;

        }
         if(kierunek==2 and pra==true)//sprawdza czy wylosowany kierunek to w prawo i czy jest tam miejsce
      {

          for(i=0;i<6;i++)
          {if(k==0 and i==0)
             i=1;
            if(k==6 and i==5)
                break;
              if(i>0 and i<5)
             {
              p[w][k+i-1]=4;
             }
             else
                p[w][k+i-1]=-1;
             if(w!=9)
             p[w+1][k-1+i]=-1;
           if(w!=0)
            p[w-1][k-1+i]=-1;}
            c=0;

        }
                 if(kierunek==3 and lew==true)//sprawdza czy wylosowany kierunek to w lewo i czy jest tam miejsce
      {
          for(i=0;i<6;i++)
          {if(k==9 and i==0)
          i=1;
          if(k==3 and i==5)
            break;
              if(i>0 and i<5)
             {
              p[w][k-i+1]=4;
             }
             else
                p[w][k-i+1]=-1;
             if(w!=9)
             p[w+1][k+1-i]=-1;
            if(w!=0)
            p[w-1][k+1-i]=-1;}
            c=0;

        }}





}

void statki(int p[10][10],int n)//rozstawia statek o dlugosci n
{
     int w,k,c=1,z=1,kierunek,i;
    //cztero
    //1gora 2dol 3prawo 4lewo
    int s=0,pr=5,le=5,go=5,dl=5;
        bool pra=true,lew=true,gor=true,dol=true;
z=1;
    while(z!=0)
    { s=0;pr=5;le=5;go=5;dl=5;
         pra=true;lew=true;gor=true;dol=true;
    w=rand()%10;
    k=rand()%10;
    if(w<n-1)
    {gor=false;
    }
    if(w>10-n)
        dol=false;
    if(k>10-n)
        pra=false;
    if(k<n-1)
        lew=false;
       if(gor)
            {
               for(i=0;i<n;i++)//sprawdZa czy jesli wstawimy statek nie zetknie sie z innym
               {if(p[w-i][k]!=0)
                {gor=false;
                break;
                }
               }
            }
                 if(dol)
            {
               for(i=0;i<n;i++)
               {if(p[w+i][k]!=0)
                {dol=false;
                break;
                }
               }
            }
                 if(pra)
            {
               for(i=0;i<n;i++)
               {if(p[w][k+i]!=0)
                {pra=false;
                break;
                }
               }
            }
                 if(lew)
            {
               for(i=0;i<n;i++)
               {if(p[w][k-i]!=0)
                {lew=false;
                break;
                }
               }
            }
           if(gor)//jesli jest opcja postawienie tam statku dodaje do losowanych
                {go=s;
                s++;
                    }
                if(dol)
                {dl=s;
                s++;
                   }
            if(pra)
                {pr=s;
                s++;
                    }
                if(lew)
                {le=s;
                s++;
                    }

                if(s>0)//sprawdzam czy wgl jest jakas opcja
                   {z=0;
                  }
        }

    s=s-1;//zmniejszam bo jest opcja 0

        if(s==0)
            kierunek=s;
        else
          kierunek=rand()%s;//losuje kierunek

      if(kierunek==go and gor==true)
      {
          for(i=0;i<n+2;i++)
          {if(w==9 and i==0)
            i=1;
            if(w==n-1 and i==n+1)
                break;
            if(i>0 and i<n+1)
             {
                 p[w-i+1][k]=n;//stawia statek
             }
             else
                {
                    p[w-i+1][k]=-1;}//staweia -1 do okola
             if(k!=9 )
             p[w-i+1][k+1]=-1;
            if(k!=0)
            p[w-i+1][k-1]=-1;}
            c=0;

        }
     if(kierunek==dl and dol==true)

        {
          for(i=0;i<n+2;i++)
          {     if(w==0 and i==0)
        i=1;

      if(w==10-n and i==n+1)
           break;
              if(i>0 and i<n+1)
             {
              p[w+i-1][k]=n;
             }
             else
                p[w+i-1][k]=-1;
            if(k!=9 )
             p[w+i-1][k+1]=-1;
            if(k!=0)
            p[w+i-1][k-1]=-1;}


        }
         if(kierunek==pr and pra==true)
      {

          for(i=0;i<n+2;i++)
          {if(k==0 and i==0)
             i=1;
            if(k==10-n and i==n+1)
                break;
              if(i>0 and i<n+1)
             {
              p[w][k+i-1]=n;
             }
             else
                p[w][k+i-1]=-1;
             if(w!=9)
             p[w+1][k-1+i]=-1;
           if(w!=0)
            p[w-1][k-1+i]=-1;}


        }
                 if(kierunek==le and lew==true)
      {
          for(i=0;i<n+2;i++)
          {if(k==9 and i==0)
          i=1;
          if(k==n-1 and i==n+1)
            break;
              if(i>0 and i<n+1)
             {
              p[w][k-i+1]=n;
             }
             else
                p[w][k-i+1]=-1;
             if(w!=9)
             p[w+1][k+1-i]=-1;
            if(w!=0)
            p[w-1][k+1-i]=-1;}


    }

}
void wypisz(int p[10][10])//wypisuje plansze int
{
    int i,j;
    cout<<"   "<<"a"<<" "<<"b"<<" "<<"c"<<" "<<"d"<<" "<<"e"<<" "<<"f"<<" "<<"g"<<" "<<"h"<<" "<<"i"<<" "<<"j"<<endl;
    for(i=0;i<10;i++)
    { if(i!=0)
    cout<<endl;

    cout<<i<<"|";
        for(j=0;j<10;j++)
        { cout.width(2);
            cout<<p[i][j];}
    }

}
void wypisz2(char p[10][10])//wypisuje plansze znakow
{
    int i,j;
    cout<<"   "<<"a"<<" "<<"b"<<" "<<"c"<<" "<<"d"<<" "<<"e"<<" "<<"f"<<" "<<"g"<<" "<<"h"<<" "<<"i"<<" "<<"j"<<endl;
    for(i=0;i<10;i++)
    { if(i!=0)
    cout<<endl;

    cout<<i<<"|";
        for(j=0;j<10;j++)
        { cout.width(2);
            cout<<p[i][j];}
    }

}
void uzu2(int p[10][10],int n)//stawianie stATkow dlugosci n przez gracza
{
    int i,e=0,w,k,c,z=0;
    char o;
while(z!=1)//trwa tak dlugo puki statek nie zostanie poprawnie ustawiony
    {int kp=0;

        cout<<endl<<"podaj kolumne  w ktorej chcesz postawic "<<n<<" masztowiec"<<endl;
        while(kp==0)
        {
            cin>>o;
            if(o<108 and o>96)
                kp++;
            else
                cout<<"podales kolumne spoza zakresu lub z duzej litery podaj poprawna"<<endl;}


                 while(kp==1)
        {  cout<<"podaj wiersz  w ktorym chcesz postawic "<<n<<" masztowiec"<<endl;

            while(!(cin>>w))//sprawdza by nie mozna wstawic litery
            {   cout<<"nie podales liczby podaj liczbe"<<endl;
                cin.clear();
                cin.sync();
            }

            if(w<10 and w>=0)
                kp--;
            else
                cout<<"podales wiersz spoza zakresu podaj poprawny"<<endl;
            }

            k=o-97;
    //cztero
    //1gora 2dol 3prawo 4lewo
    int s=0,pr=5,le=5,go=5,dl=5;
        bool pra=true,lew=true,gor=true,dol=true;

    s=0;pr=5;le=5;go=5;dl=5;
         pra=true;lew=true;gor=true;dol=true;

    if(w<n-1)
    {gor=false;
    }
    if(w>10-n)
        dol=false;
    if(k>10-n)
        pra=false;
    if(k<n-1)
        lew=false;
       if(gor)
            {
               for(i=0;i<n;i++)
               {if(p[w-i][k]!=0)
                {gor=false;
                break;
                }
               }
            }
                 if(dol)
            {
               for(i=0;i<n;i++)
               {if(p[w+i][k]!=0)
                {dol=false;
                break;
                }
               }
            }
                 if(pra)
            {
               for(i=0;i<n;i++)
               {if(p[w][k+i]!=0)
                {pra=false;
                break;
                }
               }
            }
                 if(lew)
            {
               for(i=0;i<n;i++)
               {if(p[w][k-i]!=0)
                {lew=false;
                break;
                }
               }
            }
if(gor==false and dol==false and pra==false and lew==false)//sprawdza czy jest jaki kolwiek kierunek jak nie wraca do poczatku i wybiera na nowo
    cout<<"nie mozesz w tym miejscu ustawic poniewaz jest za malo miejsca lub jest juz tam ustawiony inny statek"<<endl;
else{
    cout<<"wybierz kierunek z dostepnych:"<<endl;//podaje dostepne kierunki
    if(gor)
        cout<<"gora"<<endl;
    if(dol)
        cout<<"dol"<<endl;
    if(pra)
        cout<<"prawo"<<endl;
        if(lew)
        cout<<"lewo"<<endl;

string kierunek;
int q=0;
if(n==1)
{
kierunek="dol";
}
else{
while(q==0)
{cin>>kierunek;
if(kierunek!="prawo" and kierunek!="gora" and kierunek!="lewo" and kierunek!="dol")//sprawdza czy podany kierunek istneije
    cout<<"wybrano kierunek ktory nie istnieje wybierz poprawny"<<endl;
 else{if(kierunek=="gora" and gor==true)
       q++;
 else{if(kierunek=="dol" and dol==true)
       q++;
 else{if(kierunek=="prawo" and pra==true)
       q++;
 else{if(kierunek=="lewo" and lew==true)
         q++;
         else
            cout<<"podany kierunek jest zajety i nie mozna go wybrac wybiez poprawny"<<endl;//jesli w danym kierunku nie mozna ustawic
         }}}

 }}}

    if(kierunek=="gora" and gor==true)
      {
          for(i=0;i<n+2;i++)
          {if(w==9 and i==0)
            i=1;
            if(w==n-1 and i==n+1)
                break;
            if(i>0 and i<n+1)
             {
                 p[w-i+1][k]=n;
             }
             else
                {
                    p[w-i+1][k]=-1;}
             if(k!=9 )
             p[w-i+1][k+1]=-1;
            if(k!=0)
            p[w-i+1][k-1]=-1;}
            c=0;
      z=1;
        }
     if(kierunek=="dol" and dol==true)

        {
          for(i=0;i<n+2;i++)
          {     if(w==0 and i==0)
        i=1;

      if(w==10-n and i==n+1)
           break;
              if(i>0 and i<n+1)
             {
              p[w+i-1][k]=n;
             }
             else
                p[w+i-1][k]=-1;
            if(k!=9 )
             p[w+i-1][k+1]=-1;
            if(k!=0)
            p[w+i-1][k-1]=-1;}

        z=1;
        }
         if(kierunek=="prawo" and pra==true)
      {

          for(i=0;i<n+2;i++)
          {if(k==0 and i==0)
             i=1;
            if(k==10-n and i==n+1)
                break;
              if(i>0 and i<n+1)
             {
              p[w][k+i-1]=n;
             }
             else
                p[w][k+i-1]=-1;
             if(w!=9)
             p[w+1][k-1+i]=-1;
           if(w!=0)
            p[w-1][k-1+i]=-1;}
         z=1;

        }
                 if(kierunek=="lewo" and lew==true)
      {
          for(i=0;i<n+2;i++)
          {if(k==9 and i==0)
          i=1;
          if(k==n-1 and i==n+1)
            break;
              if(i>0 and i<n+1)
             {
              p[w][k-i+1]=n;
             }
             else
                p[w][k-i+1]=-1;
             if(w!=9)
             p[w+1][k+1-i]=-1;
            if(w!=0)
            p[w-1][k+1-i]=-1;}

      z++;
    }
}}}
int sprawdzacz(int t[10][10],vector <string>y)//sprawdza czy jest jakas pozycja specjalna na ktorej jest wieksza szansa trafic
{
    int i,j,p=0;
    string g,e;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(t[i][j]==2)
            {
                p++;

            }
        }
    }
    return p;

}
vector <string>sprawdzacz1(int t[10][10],vector <string>y)//wrzuca opcje do vectora
{
    int i,j,p=0;
    string g,e;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(t[i][j]==2)
            {
                p++;
                g=char(i+48);
                e=char(j+48);
                g=g+e;
                y.push_back(g);
            }
        }
    }
    return y;

}
void skreslacz(int f[10][10])//-1 daje w planszy wyborow wokol statku by tam nie strzelano
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(f[i][j]==5)
            {
                if(i!=0)
                    {if(f[i-1][j]!=5 )
                        f[i-1][j]=-1;
                     if(j!=0)
                     {if(f[i-1][j-1]!=5)
                        f[i-1][j-1]=-1;
                        if(f[i][j-1]!=5)
                        f[i][j-1]=-1;
                        }
                    if(j!=9)
                        {
                            if(f[i-1][j+1]!=5)
                        f[i-1][j+1]=-1;
                        if(f[i][j+1]!=5)
                        f[i][j+1]=-1;
                        }
                    }
                    if(i!=9)
                    {if(f[i+1][j]!=5 )
                        f[i+1][j]=-1;
                     if(j!=0)
                     {if(f[i+1][j-1]!=5)
                        f[i+1][j-1]=-1;
                        if(f[i][j-1]!=5)
                        f[i][j-1]=-1;
                        }
                    if(j!=9)
                        {
                            if(f[i+1][j+1]!=5)
                        f[i+1][j+1]=-1;
                        if(f[i][j+1]!=5)
                        f[i][j+1]=-1;
                        }


            }
        }
    }
}
}



int strzelaniec(int p[10][10],char t[10][10],int b)//strzelannie przez gracza
{
  int i,e=0,w,k,c,h;
    char o;


    while(e==0)//działa  tak długo jak statek bedzie mial miejsce w dowolonym kierunku
        { int kp=0;
            cout<<endl<<"podaj adres kolumny w ktora chcesz strzelic "<<endl;
        while(kp==0)
        {
            cin>>o;
            if(o<108 and o>96)//sprawdza czy jest mala litera z okreslonych liter
                kp++;
            else
                cout<<"podales kolumne spoza zakresu lub z duzej litery podaj poprawna"<<endl;}

           cout<<"podaj wiersz  w ktorym chcesz strzelic "<<endl;
                 while(kp==1)
        {
                   while(!(cin>>w))//sprawdza by nie podano litery do inta
            {   cout<<"nie podales liczby podaj liczbe"<<endl;
                cin.clear();
                cin.sync();
            }
            if(w<10 and w>=0)
                kp--;
            else
                cout<<"podales wiersz spoza zakresu podaj poprawny"<<endl;}
k=o-97;//zamienia litere na inta
if(t[w][k]!='O' and t[w][k]!='#' and t[w][k]!='@')//sprawdza czy nie strzelano tam wczesniej
    e++;
else
    cout<<"podales punkt w ktory juz strzelales podaj poprawny punkt"<<endl;
        }
        h=p[w][k];


if(p[w][k]==1)
    {t[w][k]='@';
    cout<<"trafiony zatopiony!"<<endl;
    b--;}
else{if(p[w][k]==0 or p[w][k]==-1 )
        {
            t[w][k]='O';
            cout<<"pudlo"<<endl;

        }
        else{b--;
                p[w][k]=5;
       if(h==2)
           {if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h )//sprawdza czy sa jeszcze jakies części statku do zestrzelenia
            {t[w][k]='#';
            cout<<"trafiony pali sie"<<endl;
        }
        else{
            t[w][k]='@';
            cout<<"trafiony zatopiony"<<endl;
        }}


        if(h==4)
           {if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h or p[w][k-2]==h or p[w][k+2]==h or p[w-2][k]==h or p[w+2][k]==h or p[w][k-3]==h or p[w][k+3]==h or p[w-3][k]==h or p[w+3][k]==h )
            {t[w][k]='#';
            cout<<"trafiony pali sie"<<endl;
        }
        else{
            t[w][k]='@';
            cout<<"trafiony zatopiony"<<endl;
        }}
        if(h==3)
        {
            if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h )
            {t[w][k]='#';
            cout<<"trafiony pali sie"<<endl;
        }
        else{
             if(p[w][k-2]==h and p[w][k-1]!=-1)
             {
                 t[w][k]='#';
            cout<<"trafiony pali sie"<<endl;
             }
             else{
                    if(p[w][k+2]==h and p[w][k+1]!=-1)
             {
                 t[w][k]='#';
            cout<<"trafiony pali sie"<<endl;
             }
             else{if(p[w-2][k]==h and p[w-1][k]!=-1)
             {
                 t[w][k]='#';
            cout<<"trafiony pali sie"<<endl;
             }
             else{if(p[w+2][k]==h and p[w+1][k]!=-1)
             {
                 t[w][k]='#';
            cout<<"trafiony pali sie"<<endl;
             }
             else{

                t[w][k]='@';
            cout<<"trafiony zatopiony"<<endl;
             }


        }}}}}

}
}return b;}
int strzelaniek2(int p[10][10],char t[10][10],int b,int f[10][10])//strzelanie poziom 2
{
vector <string>y;
vector <string>r;
      int i,e=0,w,k,c=0,h,a,l,zm=0,x;
    char o;
    a=sprawdzacz(f,y);//sprawdza czy jest jakas pozycja na ktora jest wieksza szansa trafic i czy wczesniej trafiono

    if(a==0)
    {while(c!=1)
    {k=rand()%10;
    w=rand()%10;//losuje i sprawdza czy tam nie strzelano lub czy nie jest zablokowana
        if(f[w][k]==0)
            c=1;
    }}
    else{c=0;
    while(c!=1)
     {
         y=sprawdzacz1(f,r);//wrzuca specjalne pozycje do wektora

    x=y.size()-1;
        if(a==1)
            l=0;
        else
          l=rand()%x;
    w=y[l][0]-48;
    k=y[l][1]-48;

    if(t[w][k]==0)
        c++;
    }

    zm++;}


    h=p[w][k];
    if(p[w][k]==1)
    {t[w][k]='@';
    cout<<"komputer trafia w twoj statek i zatapia go!"<<endl;
    b--;
    f[w][k]=5;
    p[w][k]=5;
    skreslacz(f);
    }
else{if(p[w][k]==0 or p[w][k]==-1 )
        {
            t[w][k]='O';
            cout<<"komputer pudluje "<<endl;
            f[w][k]=-1;

        }
        else{b--;
                p[w][k]=5;
                f[w][k]=5;
       if(h==2)
           {if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h )
            {t[w][k]='#';
            cout<<"komputer trafia w twoj statek i pali sie"<<endl;
             f[w][k]=5;
             p[w][k]=5;
            }
        else{
            t[w][k]='@';
            cout<<"komputer trafiona w twoj statek i zatapia go"<<endl;
             f[w][k]=5;
             p[w][k]=5;
            skreslacz(f);
        }}


        if(h==4)
           {if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h or p[w][k-2]==h or p[w][k+2]==h or p[w-2][k]==h or p[w+2][k]==h or p[w][k-3]==h or p[w][k+3]==h or p[w-3][k]==h or p[w+3][k]==h )
            {t[w][k]='#';
            p[w][k]=5;
            cout<<"komputer trafia w twoj statek i pali sie"<<endl;
             f[w][k]=5;


        }
        else{
            t[w][k]='@';
             f[w][k]=5;
             p[w][k]=5;
            skreslacz(f);


            cout<<"komputer trafia twoj statek i zatopia go"<<endl;
        }}
        if(h==3)
        {
            if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h )
            {t[w][k]='#';
            p[w][k]=5;
            f[w][k]=5;
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;

        }
        else{
             if(p[w][k-2]==h and p[w][k-1]!=-1)
             {f[w][k]=5;
                 p[w][k]=5;
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;


             }
             else{
                    if(p[w][k+2]==h and p[w][k+1]!=-1)
             {p[w][k]=5;
             f[w][k]=5;
                 t[w][k]='#';
                 }
             else{if(p[w-2][k]==h and p[w-1][k]!=-1)
             {f[w][k]=5;
             p[w][k]=5;
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;


             }
             else{if(p[w+2][k]==h and p[w+1][k]!=-1)
             {f[w][k]=5;
             p[w][k]=5;
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;

             }
             else{

                t[w][k]='@';
                f[w][k]=5;
                p[w][k]=5;
            cout<<"komputer trafia w twoj statek i zatapia go"<<endl;
             skreslacz(f);
             }


        }}}}}
if(t[w][k]=='#')
{
//sprawdzaja czy byl wczesniejszy gdzies obok trafiony jesli byl o tej samej kolumnie to wie ze nie bedzie o tym samym wierszu i wykresla taka samo na odwrot

                 if(f[w-1][k]==5 and w!=0)
                 {   if(w!=9 and  f[w+1][k]!=-1)
                     {f[w+1][k]=2;}
                     if(w!=0 and k!=9)
                     {f[w-1][k+1]=-1;}
                    if(w!=0 and k!=0)
                      f[w-1][k-1]=-1;

                    if(k!=9)
                        f[w][k+1]=-1;
                    if(k!=0)
                    f[w][k-1]=-1;
                 }
                 if(f[w+1][k]==5 and w!=9)
                 {if(w!=0 and f[w-1][k]==0)
                     f[w-1][k]=2;
                     if(k!=9)
                     f[w+1][k+1]=-1;
                      if(k!=0)
                      f[w+1][k-1]=-1;


                    if(k!=9)
                        f[w][k+1]=-1;
                    if(k!=0)
                    f[w][k-1]=-1;}

                if(f[w][k-1]==5 and k!=0)
                 {   if(k!=9 and f[w][k+1]==0)
                     f[w][k+1]=2;
                     if( w!=0)
                     f[w-1][k-1]=-1;
                           if(w!=9 and k!=0)
                      f[w+1][k-1]=-1;
                      if(w!=9)
                        f[w+1][k]=-1;
                    if(w!=0)
                    f[w-1][k]=-1;

                 }
                 if(f[w][k+1]==5 and k!=9)
                 {if(k!=0 and f[w-1][k]==0)
                     f[w][k-1]=2;

                    if(w!=9)
                        f[w+1][k]=-1;
                    if(w!=0)
                    f[w-1][k]=-1;
                     if(w!=9)
                     f[w+1][k+1]=-1;
                      if(w!=0)
                      f[w-1][k+1]=-1;

                 }
//jesli trafi sie to ustawia gdzie jest mozliwe trafionie pozycje obok trafionej

    if(f[w+1][k]==0 and w!=9)
        f[w+1][k]=2;

        if(f[w-1][k]==0 and w!=0)
        f[w-1][k]=2;
         if(f[w][k-1]==0 and k!=0)
        f[w][k-1]=2;
            if(f[w][k+1]==0 and k!=9)
        f[w][k+1]=2;


}
}
}


y.clear();return b;}



bool miejsce(int w,int k,int p[10][10],int n,int a)//sprawdza czy jest miejsce na statek czy dany  strzal ma sens
{
   bool czy;
int s=0,pr=5,le=5,go=5,dl=5,sro=0,bok=0,i;
        bool pra=true,lew=true,gor=true,dol=true;

    s=0;pr=5;le=5;go=5;dl=5;
         pra=true;lew=true;gor=true;dol=true;


       if(gor)
            {
               for(i=0;i<10;i++)
               {if(p[w-i][k]==-1)
                {gor=false;
                break;
                }
                else
                    sro++;
                if(w-i==0)
                    break;
               }
            }
                 if(dol)
            {
               for(i=0;i<10;i++)
               {if(p[w+i][k]==-1)
                {dol=false;
                break;
                }
                else
                    sro++;
                 if(w+i==9)
                    break;
               }
            }
                 if(pra)
            {
               for(i=0;i<10;i++)
               {if(p[w][k+i]==-1)
                {pra=false;
                break;
                }
                else
                    bok++;
                 if(k+i==9)
                    break;
               }
            }
                 if(lew)
            {
               for(i=0;i<10;i++)
               {if(p[w][k-i]==-1)
                {lew=false;
                break;
                }
                else
                    bok++;
                 if(k-i==0)
                    break;
               }
            }
if(bok<n and sro<n)
   czy=false;

else
{
    czy=true;
}
if(a>0)
{
if(bok<n and sro>=n)
    {if(k!=0)
        p[w][k-1]=-1;
        if(k!=9)
    p[w][k+1]=-1;}
    if(bok>=n and sro<n)
    {if(w!=9)
        p[w+1][k]=-1;
    if(w!=0)
    p[w-1][k]=-1;

    }
}
return czy;
}

int strzelaniek3(int p[10][10],char t[10][10],int b,int f[10][10],int g[5])//poziom3
{
vector <string>y;
vector <string>r;
bool czy;
      int i,e=0,w,k,c=0,h,a,l,zm=0,x,minq=5;
      for(i=1;i<5;i++)
      {
          if(g[i]!=0 and i<minq)
          {
              minq=i;//szuka najmniejszy statek jaki mu zostal do rozstawienia
          }
      }
    char o;
    a=sprawdzacz(f,y);

    if(a==0)
    {while(c!=1)
    {k=rand()%10;
    w=rand()%10;
 czy=miejsce(w,k,f,minq,a);//sprawdza czy jest miejsce na statek conajmniej najmniejszy
        if(f[w][k]==0 and czy==true)
            c=1;
    }}
    else{c=0;
    while(c!=1)
     {
         y=sprawdzacz1(f,r);

    x=y.size()-1;
        if(a==1)
            l=0;
        else
          l=rand()%x;
    w=y[l][0]-48;
    k=y[l][1]-48;
 czy=miejsce(w,k,f,minq,a);
    if(f[w][k]==2 and czy==true)
        c++;
    }

    zm++;}


    h=p[w][k];
    if(p[w][k]==1)
    {t[w][k]='@';
    cout<<"komputer trafia w twoj statek i zatapia go!"<<endl;
    b--;
    f[w][k]=5;
    p[w][k]=5;
    skreslacz(f);
    g[1]--;
    }
else{if(p[w][k]==0 or p[w][k]==-1 )
        {
            t[w][k]='O';
            cout<<"komputer pudluje "<<endl;
            f[w][k]=-1;

        }
        else{b--;
                p[w][k]=5;
                f[w][k]=5;
       if(h==2)
           {if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h )
            {t[w][k]='#';
            cout<<"komputer trafia w twoj statek i pali sie"<<endl;
             f[w][k]=5;
             p[w][k]=5;
            }
        else{
            t[w][k]='@';
            cout<<"komputer trafiona w twoj statek i zatapia go"<<endl;
             f[w][k]=5;
             p[w][k]=5;
             g[2]--;
            skreslacz(f);
        }}


        if(h==4)
           {if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h or p[w][k-2]==h or p[w][k+2]==h or p[w-2][k]==h or p[w+2][k]==h or p[w][k-3]==h or p[w][k+3]==h or p[w-3][k]==h or p[w+3][k]==h )
            {t[w][k]='#';
            p[w][k]=5;
            cout<<"komputer trafia w twoj statek i pali sie"<<endl;
             f[w][k]=5;


        }
        else{g[4]--;
            t[w][k]='@';
             f[w][k]=5;
             p[w][k]=5;
            skreslacz(f);


            cout<<"komputer trafia twoj statek i zatopia go"<<endl;
        }}
        if(h==3)
        {
            if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h )
            {t[w][k]='#';
            p[w][k]=5;
            f[w][k]=5;
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;

        }
        else{
             if(p[w][k-2]==h and p[w][k-1]!=-1)
             {f[w][k]=5;
                 p[w][k]=5;
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;


             }
             else{
                    if(p[w][k+2]==h and p[w][k+1]!=-1)
             {p[w][k]=5;
             f[w][k]=5;
                 t[w][k]='#';
                 }
             else{if(p[w-2][k]==h and p[w-1][k]!=-1)
             {f[w][k]=5;
             p[w][k]=5;
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;


             }
             else{if(p[w+2][k]==h and p[w+1][k]!=-1)
             {f[w][k]=5;
             p[w][k]=5;
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;

             }
             else{
                g[3]--;
                t[w][k]='@';
                f[w][k]=5;
                p[w][k]=5;
            cout<<"komputer trafia w twoj statek i zatapia go"<<endl;
             skreslacz(f);
             }


        }}}}}
if(t[w][k]=='#')
{


                 if(f[w-1][k]==5 and w!=0)
                 {   if(w!=9 and  f[w+1][k]!=-1)
                     {f[w+1][k]=2;}
                     if(w!=0 and k!=9)
                     {f[w-1][k+1]=-1;}
                    if(w!=0 and k!=0)
                      f[w-1][k-1]=-1;

                    if(k!=9)
                        f[w][k+1]=-1;
                    if(k!=0)
                    f[w][k-1]=-1;
                 }
                 if(f[w+1][k]==5 and w!=9)
                 {if(w!=0 and f[w-1][k]==0)
                     f[w-1][k]=2;
                     if(k!=9)
                     f[w+1][k+1]=-1;
                      if(k!=0)
                      f[w+1][k-1]=-1;


                    if(k!=9)
                        f[w][k+1]=-1;
                    if(k!=0)
                    f[w][k-1]=-1;}

                if(f[w][k-1]==5 and k!=0)
                 {   if(k!=9 and f[w][k+1]==0)
                     f[w][k+1]=2;
                     if( w!=0)
                     f[w-1][k-1]=-1;
                           if(w!=9 and k!=0)
                      f[w+1][k-1]=-1;
                      if(w!=9)
                        f[w+1][k]=-1;
                    if(w!=0)
                    f[w-1][k]=-1;

                 }
                 if(f[w][k+1]==5 and k!=9)
                 {if(k!=0 and f[w-1][k]==0)
                     f[w][k-1]=2;

                    if(w!=9)
                        f[w+1][k]=-1;
                    if(w!=0)
                    f[w-1][k]=-1;
                     if(w!=9)
                     f[w+1][k+1]=-1;
                      if(w!=0)
                      f[w-1][k+1]=-1;

                 }



    if(f[w+1][k]==0 and w!=9)
        f[w+1][k]=2;

        if(f[w-1][k]==0 and w!=0)
        f[w-1][k]=2;
         if(f[w][k-1]==0 and k!=0)
        f[w][k-1]=2;
            if(f[w][k+1]==0 and k!=9)
        f[w][k+1]=2;


}
}
}


y.clear();return b;}



int strzelaniek(int p[10][10],char t[10][10],int b)
{

      int i,e=0,w,k,c=0,h;
    char o;
    while(c!=1)
    {k=rand()%10;
    w=rand()%10;
        if(t[w][k]==0)
            c=1;

    }
    h=p[w][k];
    if(p[w][k]==1)
    {t[w][k]='@';
    cout<<"komputer trafia w twoj statek i zatapia go!"<<endl;
    b--;}
else{if(p[w][k]==0 or p[w][k]==-1 )
        {
            t[w][k]='O';
            cout<<"komputer pudluje"<<endl;

        }
        else{b--;
                p[w][k]=5;
       if(h==2)
           {if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h )
            {t[w][k]='#';
            cout<<"komputer trafia w twoj statek i pali sie"<<endl;
        }
        else{
            t[w][k]='@';
            cout<<"komputer trafia w twoj statek i zatopia go"<<endl;
        }}


        if(h==4)
           {if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h or p[w][k-2]==h or p[w][k+2]==h or p[w-2][k]==h or p[w+2][k]==h or p[w][k-3]==h or p[w][k+3]==h or p[w-3][k]==h or p[w+3][k]==h )
            {t[w][k]='#';
            cout<<"komputer trafia w twoj statek i pali sie"<<endl;
        }
        else{
            t[w][k]='@';
            cout<<"komputer trafia twoj statek i zatopia go"<<endl;
        }}
        if(h==3)
        {
            if(p[w][k-1]==h or p[w][k+1]==h or p[w-1][k]==h or p[w+1][k]==h )
            {t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;
        }
        else{
             if(p[w][k-2]==h and p[w][k-1]!=-1)
             {
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;
             }
             else{
                    if(p[w][k+2]==h and p[w][k+1]!=-1)
             {
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;
             }
             else{if(p[w-2][k]==h and p[w-1][k]!=-1)
             {
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;
             }
             else{if(p[w+2][k]==h and p[w+1][k]!=-1)
             {
                 t[w][k]='#';
            cout<<"komputer trafia w twoj statek i  pali sie"<<endl;
             }
             else{

                t[w][k]='@';
            cout<<"komputer trafia w twoj statek i zatapia go"<<endl;
             }


        }}}}}

}
}return b;}


int main()
{

    int ffff=0;
while(ffff==0)
   { HANDLE hOut;
hOut = GetStdHandle( STD_OUTPUT_HANDLE );//do koloru

 SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );//ustawia na kolor zloty


    char u=92;//znaczek z ktorym wyskakuje blad
    cout<<"         __           __    _      _"<<endl;
    cout<<"       _|  |_       _|  |_ | |    |_|"<<endl;
    cout<<"  ____|_    _|_____|_    _|| | _   _ "<<endl;
    cout<<" / ___/ |  | / __  | |  |  | |/ / | |"<<endl;
    cout<<" "<<u<<"___ "<<u<<" |  || |__| | |  |  | |"<<u<<" "<<u<<" | |"<<endl;
    cout<<" |____/ |__| "<<u<<"______"<<u<<"|__|  |_| "<<u<<"_"<<u<<"|_|"<<endl<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<"                      _ ___ "<<endl;
     cout<<"                     | |   "<<u<<endl;

       cout<<"1-Zasady gry         | |    "<<u<<endl<<"2-singleplayer       | |     "<<u<<endl<<"3-multiplayer  ______| |______"<<u<<endl;
         cout<<"               "<<u<<"            /"<<endl;
     cout<<"                "<<u<<"__________/"<<endl;
    int a,aaa=0,v,vv,w,k=20,k1=20,i,j,p,kk1,kk2;
//stworzyl napis i obrazek
    while(aaa==0)
    {while(!(cin>>w))
    {//sprawdza by wprowadzona zostala przez uzytkownika lliczba
         cout<<"nie podales liczby podaj liczbe"<<endl;
                cin.clear();
                cin.sync();
    }
    if(w==1 or w==2 or w==3)//sprawdza czy zostala wybrana ktoras z opcji
        aaa++;
    else
        cout<<"twoja opcja nie istnieje"<<endl;

    }
    switch(w)//uruchamia wybrana opcje
    {case 1:if(w==1){cout<<"Zasady gry: Kazdy gracz ustawia na swojej planszy jeden czteromasztowiec dwa trzymaszstowce trzy dwumasztowce i cztery jednomasztowce Gra przebiega naprzemiennie: najpierw jeden z graczy oddaje strzal, jesli uda sie mu trafic, moze kontynuowac strzelanie do momentu, az chybi. Zatopienie statku ma miejsce, kiedy wszystkie kratki symbolizujace ten okret zostana trafione przez drugiego gracza."<<endl;}
    case 2:if(w==2){    int plansza[10][10]{},planszag[10][10]{},f[10][10]{};
    char pl2[10][10]{},plk[10][10]{};
      srand(time(NULL));
      int g[5]{};
      for(i=1;i<5;i++)
        g[i]=5-i;
int pp=0,kk1,kk2;
while(pp!=1)
{cout<<"wybierz poziom trudnosci"<<endl;
cout<<"1-latwy"<<endl<<"2-sredni"<<endl<<"3-trudny"<<endl;
       while(!(cin>>p))//wybor poziomu trudnosci
            {   cout<<"nie podales liczby podaj liczbe"<<endl;
                cin.clear();
                cin.sync();
            }
if(p==1 or p==2 or p==3)
    pp=1;
else
    cout<<"wybrales poziom ktory nie istnieje"<<endl;
}
     uzu(plansza);
          statki(plansza,3);//uzupelnia plansze statkami

     statki(plansza,3);

     statki(plansza,2);

     statki(plansza,2);

      statki(plansza,2);

     statki(plansza,1);
     statki(plansza,1);
     statki(plansza,1);

     statki(plansza,1);
     wypisz(planszag);

          uzu2(planszag,4);
     wypisz(planszag);
     uzu2(planszag,3);
     wypisz(planszag);
      uzu2(planszag,3);
      wypisz(planszag);
     uzu2(planszag,2);
     wypisz(planszag);
      uzu2(planszag,2);
      wypisz(planszag);
     uzu2(planszag,2);
     wypisz(planszag);
      uzu2(planszag,1);
      wypisz(planszag);
     uzu2(planszag,1);
      wypisz(planszag);
      uzu2(planszag,1);
     wypisz(planszag);
     uzu2(planszag,1);
wypisz(planszag);



     while(k!=0 or k1!=0)
     {vv=0;
         a=k;
         cout<<endl<<"strzelasz"<<endl;
         cout<<endl<<"oto pola planszy ktore mozesz wybrac"<<endl;
         cout<<endl;
         wypisz2(plk);
                  cout<<endl<<"oto pola planszy ktore mozesz wybrac"<<endl;
         kk1=strzelaniec(plansza,plk,k);
         k=kk1;
cout<<endl;


     wypisz2(plk);
     cout<<endl<<"oto pola planszy po twoim strzale"<<endl;
     cout<<endl<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
     if(a==k)
     { while(vv==0)//tak dlugo poki ktos nie bbedzie mial ani jedneg statku
     {v=k1;
         if(p==1)
         {kk2=strzelaniek(planszag,pl2,k1);//sprawdza czy gracz trafil
         k1=kk2;}
         if(p==2)
         {
             kk2=strzelaniek2(planszag,pl2,k1,f);
             k1=kk2;
         }
         if(p==3)
         {
                          kk2=strzelaniek3(planszag,pl2,k1,f,g);
             k1=kk2;

         }
         wypisz2(pl2);
       cout<<endl<<"oto plansza strzalow twojego przeciwnika"<<endl;
cout<<endl<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
     if(k1==v)
        vv++;
     }

     }
if(k==0 or k1==0)
    break;
     }
     if(k==0)
        cout<<"gratulacje wygrales!!!!"<<endl;
     if(k1==0)
        cout<<"niestety przegrales:("<<endl;
     cout<<"wynik:"<<endl<<"ilosc punktow trafionych przez ciebie "<<20-k<<endl<<"ilosc punktow trafionych przez komputer "<<20-k1<<endl;
  }
case 3:if(w==3){
int plansza[10][10]{},planszag[10][10]{};
    char pl2[10][10]{},plk[10][10]{};
    string g1,g2;
    cout<<"podaj nazwe gracza pierwszego"<<endl;
    cin>>g1;
    cout<<"podaj nazwe gracza drugiego"<<endl;
    cin>>g2;
    cout<<g1<<" "<<"ustaw swoje statki"<<endl;
    wypisz(plansza);
    uzu2(plansza,4);
     wypisz(plansza);
     uzu2(plansza,3);
     wypisz(plansza);
      uzu2(plansza,3);
      wypisz(plansza);
     uzu2(plansza,2);
     wypisz(plansza);
      uzu2(plansza,2);
      wypisz(plansza);
     uzu2(plansza,2);
     wypisz(plansza);
      uzu2(plansza,1);
      wypisz(plansza);
     uzu2(plansza,1);
      wypisz(plansza);
      uzu2(plansza,1);
     wypisz(plansza);
     uzu2(plansza,1);
wypisz(plansza);
system( "cls" );
cout<<g2<<" "<<"ustaw swoje statki"<<endl;
wypisz(planszag);
uzu2(planszag,4);
     wypisz(planszag);
     uzu2(planszag,3);
     wypisz(planszag);
      uzu2(planszag,3);
      wypisz(planszag);
     uzu2(planszag,2);
     wypisz(planszag);
      uzu2(planszag,2);
      wypisz(planszag);
     uzu2(planszag,2);
     wypisz(planszag);
      uzu2(planszag,1);
      wypisz(planszag);
     uzu2(planszag,1);
      wypisz(planszag);
      uzu2(planszag,1);
     wypisz(planszag);
     uzu2(planszag,1);
wypisz(planszag);
system( "cls" );
while(k!=0 or k1!=0)
     {vv=0;
         a=k;

         wypisz2(plk);
                  cout<<endl<<"oto plansza w ktora "<<g1<<" mozesz strzelac"<<endl;
         cout<<endl<<g1<<" "<<"strzelasz"<<endl;
         kk1=strzelaniec(planszag,plk,k);

     wypisz2(plk);
     cout<<endl<<"oto plansza "<<g1<<" po twoim strzale"<<endl;
     cout<<endl<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
     k=kk1;


     if(a==k)
     { while(vv==0)
     {v=k1;

         wypisz2(pl2);
         cout<<endl<<"oto plansza w ktora "<<g2<<" mozesz strzelac"<<endl;
         cout<<endl<<g2<<" "<<"strzelasz"<<endl;

         kk2=strzelaniec(plansza,pl2,k1);

         wypisz2(pl2);
         cout<<endl<<"oto plansza"<<" "<<g2<<" po twoim strzale"<<endl;
         cout<<endl<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
         k1=kk2;
     if(k1==v)
        vv++;
     }

     }if(k==0 or k1==0)
    break;

     }
     if(k==0)
        cout<<"wygrywa"<<" "<<g1<<endl;
     if(k1==0)
        cout<<"wygrywa"<<" "<<g2<<endl;
     cout<<"wynik:"<<endl<<"ilosc punktow trafionych przez"<<" "<<g1<<" :"<<20-k<<endl<<"ilosc punktow trafionych przez"<<" "<<g2<<" :"<<20-k1<<endl;

    }
    default:cout<<"nie wybrales zadnej z opcji";}
cout<<endl<<"jesli chcesz wrocic do manu wybierz 1 jesli chcesz zamknac wybierz 2"<<endl;
while(aaa==1)
{while(!(cin>>w))
    {
         cout<<"nie podales liczby podaj liczbe"<<endl;
                cin.clear();
                cin.sync();
    }
    if(w==1 or w==2)
        aaa++;
    else
        cout<<"twoja opcja nie istnieje"<<endl;
}
if(w==2)
    exit(0);
}}

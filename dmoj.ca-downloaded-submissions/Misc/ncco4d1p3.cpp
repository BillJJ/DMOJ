#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#ifdef __MINGW32__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#endif
#define ll long long
#define ld long double
static struct IO {
#define _i inline void
#define __t template<typename T>
#define __c unsigned char
#define __1(x,y,z) inline IO &operator x (y &s){z; return*this;}
#define __2 val=0;int c=gc();while(c<=' ')c=gc();bool n=(c=='-');if(n)c=gc();do{val=val*10+c-'0';}while((c=gc())>='0'&&c<='9');
#define p_str(x) for (char i: x)pc(i);
#define likely(x) __builtin_expect(x,true)
#define unlikely(x) __builtin_expect(x,false)
    const unsigned int bfz=1<<15;const static bool line_buf; __c *_rb=new __c[bfz]; __c *_wb=new __c[bfz];unsigned int rl=0,ri=0,wi=0;bool eof=false;
#ifdef _getchar_nolock
#else
#define ugc getchar
#endif
    inline __c gc(){if(line_buf){return ugc();}else{if(unlikely(ri>=rl)){if(unlikely(eof))return EOF;fill_buffer();}
            return _rb[ri++];}} _i pc(char x){if(unlikely(wi>=bfz))flush_buffer();_wb[wi++]=x;} _i fill_buffer(){auto x=fread(_rb,sizeof(char),bfz,stdin);
        if(unlikely(x!=0&&x<bfz)){eof=true;}rl=x;ri= 0;} _i flush_buffer(){fwrite(_wb,sizeof(char),wi,stdout);fflush(stdout);wi=0;}~IO(){flush_buffer();}
    __t _i _ni(T &val){__2 if(n)val=-val;} __t _i _nd(T &val){__2 T div=1;if(c=='.'){while((c=gc())>='0'&&c<='9')val+=(c-'0')/(div*=10);}if(n)val=-val;}
    _i _nt(string &s,char token=' '){ostringstream oss;int c=gc();while(c==token||c<' ')c=gc();do{oss<<static_cast<char>(c);}while((c=gc())!=token&&c>=' ');
        s=oss.str();} _i _nln(string &s){_nt(s,'\n');}static inline int fast_log10(const unsigned ll& val){return val<=9?0:val<=99?1:val<=999?2:val<=
                                                                                                                                                9999?3:val<=99999?4:val<=999999?5:val<=9999999?6:val<=99999999?7:val<=999999999?8:val<=9999999999?9:val<=99999999999?10:val<=999999999999?11:val<=
                                                                                                                                                                                                                                                                                             9999999999999?12:val<=99999999999999?13:val<=999999999999999?14:val<=9999999999999999?15:val<=99999999999999999?16:val<=999999999999999999?17:val<=
                                                                                                                                                                                                                                                                                                                                                                                                                                           9999999999999999999ull?18:val<=ULLONG_MAX?19:-1;}char buf[20]; __t _i write_int(T data){if(data==0)pc('0');else{int len;if(data<0){pc('-');data
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              =-data;}len=fast_log10(data)+1;for(int i=len-1;i>=0;i--){buf[i]=data%10+'0';data/=10;}for(int i=0;i<len;i++){pc(buf[i]);}}} __1(>,char,s=gc())
    __1(>=,char,s=' ';while(s<=' ')s=gc()) __1(>,string,_nt(s)) __1(>,ld,_nd(s)) __1(>,ll,_ni(s)) __1(>,int,_ni(s)) __1(>=,string,_nln(s))
    __1(<,const int,write_int(s)) __1(<,const ll,write_int(s)) __1(<,const ld,p_str(to_string(s));) __1(<,const string,p_str(s);)
    __1(<,const char,pc(s);)IO(){if(line_buf){std::istream::sync_with_stdio(false);cin.tie(nullptr);}
        else{setvbuf(stdin,nullptr,_IONBF,0);}setvbuf(stdout, nullptr, _IONBF, 0);}}io;
#ifdef __MINGW32__
#pragma clang diagnostic pop
const bool IO::line_buf = true;
#else
const bool IO::line_buf = false;
#endif

// > read
// < write
// >= readline (for string with spaces)
// can be used with any signed integer type
// example:
// int a;
// io > a;
// io < a;

typedef pair<int, int> pii;

vector<pii> edge1[20005];
priority_queue<pii, vector<pii>, greater<pii>> q;

int dis1[20005];
int dis2[20005];
int n;

void do_1(){
    memset(dis1, -1, sizeof dis1);
    for(pii p : edge1[1]){
        q.push(p);
    }
    dis1[1] = 0;
    while(!q.empty()){
        pii m = q.top(); q.pop();
        if(dis1[m.second] == -1){
            dis1[m.second] = m.first;
            for(pii p : edge1[m.second]){
                if(dis1[p.second] == -1){
                    q.push({p.first + m.first, p.second});
                }
            }
        }
    }
}

void do_2(){
    memset(dis2, -1, sizeof dis2);
    for(pii p : edge1[n])
        q.push(p);
    dis2[n] = 0;
    while(!q.empty()){
        pii m = q.top(); q.pop();
        if(dis2[m.second] == -1){
            dis2[m.second] = m.first;
            for(pii p : edge1[m.second]){
                if(dis2[p.second] == -1)
                    q.push({p.first + m.first, p.second});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int m; io > n > m;

    for(int i = 0; i < m; i++){
        int a, b, w; io > a > b > w;
        edge1[a].push_back({w, b});
        edge1[b].push_back({w, a});
    }
    do_1(); do_2();

    int shortest = dis1[n];
    if(dis1[n] == -1){cout << -1; return 0;}
    int second = INT_MAX;

    for(int i = 1; i <= n; i++){
        for(pii p : edge1[i]){
            int u = i, v = p.second, w = p.first;

            if(dis1[u] == -1 || dis2[v] == -1) continue;

            int path = dis1[u] + w + dis2[v];
            if(path < second && path != shortest){
                second = path;
            }
        }
    }
    if(second == INT_MAX){
        cout << -1; return 0;
    }
    io < second < '\n';
    return 0;
}
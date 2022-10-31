/*
    Author :     YASH MANIYA (codheck_0) [B20CS033]
    
    Already fallen,
    Now is the time to RISE !!!

*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

// -------- Extra Macros ---------------------------------------------------------------------------------------------
#define curtime                 chrono::high_resolution_clock::now()
#define tdif(start,end)         chrono::duration_cast<chrono::microseconds>(end - start).count()
#define timedif(start,end)      ((long double)tdif(start,end))*1e-6
auto t0 = curtime;

#define RESET                   "\033[0m"
#define BR                      "\033[1m\033[31m"      // Bold Red
#define BG                      "\033[1m\033[32m"      // Bold Green
#define BY                      "\033[1m\033[33m"      // Bold Yellow
#define BB                      "\033[1m\033[34m"      // Bold Blue
// -------------------------------------------------------------------------------------------------------------------


// -------- Macros ---------------------------------------------------------------------------------------------------
#define int                     long long int
#define ull                     unsingned long long
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define vii                     vector<int>
#define usii                    unordered_set<int>
#define sii                     set<int>
#define mii                     map<int, int>
#define umii                    unordered_map<int, int>
#define mivi                    map<int, vii>
#define umivi                   unordered_map<int, vii>
#define effi(x)                 x.max_load_factor(0.2);     // takes greater space to avoid collisions
#define pb                      push_back
#define yep                     cout<<"YES"<<endl;
#define nope                    cout<<"NO"<<endl;
#define neg1                    cout<<-1<<endl;
#define boost                   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define forl(i,n)               for(int i=0;i<n;i++)
#define itr(i,a,b)              for(int i=a;(b>=a)?i<b:i>b;(b>=a)?i++:i--)
#define print_arr(arr,n)        forl(i,n){cout<<arr[i]<<" ";}cout<<endl;
#define print_vec(v)            for(auto i:v){cout<<i<<" ";}cout<<endl;
#define print_arr2d(arr,n,m)    forl(i,n){forl(j,m){cout<<arr[i][j]<<' ';}cout<<endl;}
#define input(arr,n)            forl(i,n){cin>>arr[i];}
#define input_arr2d(arr, n, m)  forl(i,n){forl(j,m){cin>>arr[i][j];}}
#define sprec(x,y)              fixed<<setprecision(y)<<x
#define all(v)                  v.begin(),v.end()
#define rall(v)                 v.rbegin(),v.rend()
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b)) / __gcd((a),(b))
#define min3(a,b,c)             min(c, min(a, b))
#define min4(a,b,c,d)           min(d, min(c, min(a, b)))
#define max3(a,b,c)             max(c, max(a, b))
#define max4(a,b,c,d)           max(d, max(c, max(a, b)))
// --------------------------------------------------------------------------------------------------------------------


// ------ Global Constants --------------------------------------------------------------------------------------------
const int MOD = 1e9 + 7;
const int MAX_ARR = 2*1e5 + 1;
const int MAXX = INT_MAX;
const int MINN = INT_MIN;
// --------------------------------------------------------------------------------------------------------------------


// ------ Debugging Macros & Templates --------------------------------------------------------------------------------
#ifndef ONLINE_JUDGE
#define dbgR(x...)               cerr << BR << #x << RESET << " = " << BB; __print(x);
#define dbgG(x...)               cerr << BG << #x << RESET << " = " << BB; __print(x);
#define dbgY(x...)               cerr << BY << #x << RESET << " = " << BB; __print(x);
#define dbg(x...)                dbgR(x)
#else
#define dbg(x...)
#define dbgR(x...)
#define dbgG(x...)
#define dbgY(x...)
#endif
#define delim ", "

void _print(int t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
void _print(const string &t) {cerr << '\"' << t << '\"';}
void _print(bool t) {cerr << (t ? "true" : "false");}
void __print() {cerr << "\n" << RESET;}

template <typename T, typename V> void _print(pair <T, V> &p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <typename T> void _print(vector <T> &v) {int ctr=v.size(); cerr << "[ "; for (T i : v) {_print(i); cerr << ((--ctr)?delim:" ");} cerr << "]";}
template <typename T> void _print(set <T> &v) {int ctr=v.size(); cerr << "[ "; for (T i : v) {_print(i); cerr << ((--ctr)?delim:" ");} cerr << "]";}
template <typename T> void _print(unordered_set <T> &v) {int ctr=v.size(); cerr << "[ "; for (T i : v) {_print(i); cerr << ((--ctr)?delim:" ");} cerr << "]";}
template <typename T> void _print(multiset <T> &v) {int ctr=v.size(); cerr << "[ "; for (T i : v) {_print(i); cerr << ((--ctr)?delim:" ");} cerr << "]";}
template <typename T, typename V> void _print(map <T, V> &v) {int ctr=v.size(); cerr << "[ "; for (auto i : v) {_print(i); cerr << ((--ctr)?delim:" ");} cerr << "]";}
template <typename T, typename V> void _print(unordered_map <T, V> &v) {int ctr=v.size(); cerr << "[ "; for (auto i : v) {_print(i); cerr << ((--ctr)?delim:" ");} cerr << "]";}
template <typename T, typename... V> void __print(T t, V... v) {_print(t); if (sizeof...(v)) cerr << ", "; __print(v...);}

// --------------------------------------------------------------------------------------------------------------------

class SexTree{
    public:

    vii arr, sum_tree, max_tree, min_tree;
    bool need_sum, need_max, need_min;

    SexTree(vii &v, bool sm=1, bool mx=0, bool mn=0){
        arr = v;
        need_sum = sm; need_max = mx; need_min = mn;
        if (need_sum) sum_tree.resize(4*arr.size()+1);
        if (need_max) max_tree.resize(4*arr.size()+1);
        if (need_min) min_tree.resize(4*arr.size()+1);
        build(0, 0, arr.size()-1);
    }

    void build(int node, int l, int r){
        if (l==r){
            if (need_sum) sum_tree[node] = arr[l];
            if (need_max) max_tree[node] = arr[l];
            if (need_min) min_tree[node] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        int left = (node<<1)+1;
        int right = (node<<1)+2;

        build(left, l, mid);
        build(right, mid+1, r);

        if (need_sum) sum_tree[node] = sum_tree[left] + sum_tree[right];
        if (need_max) max_tree[node] = max(max_tree[left], max_tree[right]);
        if (need_min) min_tree[node] = min(min_tree[left], min_tree[right]);
    }

    void update(int ix, int val){
        point_update(0, 0, arr.size()-1, ix, val);
    }

    void point_update(int node, int l, int r, int ix, int val){
        if (l==r){
            if (need_sum) sum_tree[node] = val;
            if (need_max) max_tree[node] = val;
            if (need_min) min_tree[node] = val;
            return;
        }
        int mid = (l+r)>>1;
        int left = (node<<1)+1;
        int right = (node<<1)+2;
        
        if (ix<=mid){
            point_update(left, l, mid, ix, val);
        }
        else{
            point_update(right, mid+1, r, ix, val);
        }

        if (need_sum) sum_tree[node] = sum_tree[left] + sum_tree[right];
        if (need_max) max_tree[node] = max(max_tree[left], max_tree[right]);
        if (need_min) min_tree[node] = min(min_tree[left], min_tree[right]);
    }

    vii query(int ql, int qr){
        return query_helper(0, 0, arr.size()-1, ql, qr);
    }

    vii query_helper(int node, int l, int r, int ql, int qr){
        // complete overlap
        if (ql<=l && r<=qr){
            vii res;
            if (need_sum) res.pb(sum_tree[node]);
            else { res.pb(-1); }
            if (need_max) res.pb(max_tree[node]);
            else { res.pb(-1); }
            if (need_min) res.pb(min_tree[node]);
            else { res.pb(-1); }

            return res;
        }

        // 0 overlap
        if (r<ql || l>qr){
            vii res = {0, MINN, MAXX};
            return res;
        }

        // partial overlap
        int mid = (l+r)>>1;
        vii q1 = query_helper((node<<1)+1, l, mid, ql, qr);
        vii q2 = query_helper((node<<1)+2, mid+1, r, ql, qr);

        vii res;
        if (need_sum) res.pb(q1[0] + q2[0]);
        else { res.pb(-1); }
        res.pb(max(q1[1], q2[1]));
        res.pb(min(q1[2], q2[2]));

        return res;
    }
};

// --------------------------------------------------------------------------------------------------------------------
//                                       *** SOLN STARTS FROM HERE ***
// --------------------------------------------------------------------------------------------------------------------

// Input :

// 1
// 5 5
// 1 2 3 4 5
// 1 1 4
// 1 3 5
// 2 4 -2
// 1 1 4
// 1 3 5

// Output :     When following is used : new SexTree(v, 1, 1, 1);

// 10 4 1
// 12 5 3
// 4 3 -2
// 6 5 -2

void solve(){
    int n, q;
    cin>>n>>q;
    vii v(n);
    input(v,n)
    SexTree* seg = new SexTree(v, 1, 1, 1);         // format : (input_vector, need_sum, need_max, need_min)
    dbg("sum tree", seg->sum_tree);                 // last 3 parameters are boolean, change as per requirements
    dbg("max tree", seg->max_tree);                 // true means corresponding segment tree is created
    dbg("min tree", seg->min_tree);                 // if false, corresponding segment tree is empty (space is saved)
    while(q--){
        int mode;
        cin>>mode;
        if (mode==1){
            int l,r;
            cin>>l>>r;                              // seg->query(l-1,r-1)  will return vector of size 3 
            print_vec(seg->query(l-1,r-1));         // return vec = {range_sum, range_max, range_min}
        }                                           // if need_X is false, range_X is -1
        else{                                       
            int ix, x;
            cin>>ix>>x;
            seg->update(ix-1, x);
        }
    }
}

signed main()
{
    boost

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int t = 1;
    cin >> t;
    string breakcase = "-----";
    forl(i,4){
        breakcase+=breakcase;
    }
    while (t--)
    {
        solve();
        cerr<<breakcase<<endl;
    }

    #ifndef ONLINE_JUDGE
        cerr<< BG << "\nExecution Time: "<<timedif(t0,curtime) <<" s\n" << RESET;
    #endif
}

// --------------------------------------------------------------------------------------------------------------------


// ------- codheck_0 --------------------------------------------------------------------------------------------------
//
//                                           ,---,                                 ,-.                    ,----..    
//                                   ,---, ,--.' |                             ,--/ /|                   /   /   \   
//                     ,---.       ,---.'| |  |  :                           ,--. :/ |                  /   .     :  
//                    '   ,'\      |   | : :  :  :                           :  : ' /                  .   /   ;.  \ 
//          ,---.    /   /   |     |   | | :  |  |,--.    ,---.      ,---.   |  '  /                  .   ;   /  ` ; 
//         /     \  .   ; ,. :   ,--.__| | |  :  '   |   /     \    /     \  '  |  :                  ;   |  ; \ ; | 
//        /    / '  '   | |: :  /   ,'   | |  |   /' :  /    /  |  /    / '  |  |   \                 |   :  | ; | ' 
//       .    ' /   '   | .; : .   '  /  | '  :  | | | .    ' / | .    ' /   '  : |. \                .   |  ' ' ' : 
//       '   ; :__  |   :    | '   ; |:  | |  |  ' | : '   ;   /| '   ; :__  |  | ' \ \          ___  '   ;  \; /  | 
//       '   | '.'|  \   \  /  |   | '/  ' |  :  :_:,' '   |  / | '   | '.'| '  : |--'        .'  .`|  \   \  ',  /  
//       |   :    :   `----'   |   :    :| |  | ,'     |   :    | |   :    : ;  |,'        .'  .'   :   ;   :    /   
//        \   \  /              \   \  /   `--''        \   \  /   \   \  /  '--'       ,---, '   .'     \   \ .'
//         `----'                `----'                  `----'     `----'              ;   |  .'         `---`      
//                                                                                      `---'                        
//
// ------- ps : search for "https://codeforces.com/profile/codheck_0"  -------------------------------------------------

//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.io.*;

public class code1 
{
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t=Integer.parseInt(in.readLine());
        while(t-->0){
            String s1[]=in.readLine().trim().split(" ");
            String s2[]=in.readLine().trim().split(" ");

            Solution ob=new Solution();
            int ans=ob.prefixSuffixString(s1,s2);
            out.println(ans);

        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution
{
    public int prefixSuffixString(String s1[],String s2[])
    {
        unordered_map<string,bool> mm;
        for(auto x:s1){
            string temp="";
            for(int i=0;i<x.length();i++){
                temp+=x[i];
                mm[temp]=true;
            }
            temp="";
            for(int i=x.length()-1;i>=0;i--){
                temp=x[i]+temp;
                mm[temp]=true;
            }
        }
        int ans=0;
        for(auto x:s2){
            if(mm[x])ans++;
        }
        return ans;
    }
}

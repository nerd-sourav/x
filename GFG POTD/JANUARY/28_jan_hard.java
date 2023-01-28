

import java.util.*;
import java.io.*;
import java.lang.*;

class Geeks
{
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine().trim());
        
        while(t-- > 0)
        {
            String s[]=in.readLine().trim().split(" ");
            String a = s[0];
            String b = s[1];
            Solution g = new Solution();
            if(g.isScramble(a,b)){
                out.println("Yes");
            }
            else{
                out.println("No");
            }
        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static HashMap < String, Boolean> map;
    static boolean isScramble(String S1,String S2)
    {
        //code here
        map = new HashMap<>();
        return help(S1,S2);
    }
    static boolean help(String s1,String s2){
        if(s1.length()!=s2.length()){
            return false;
        }
        if(s1.equals(s2)){
            return true;
        }
        if(s1.length()<=1){
            return false;
        }
        if(map.containsKey(s1+" "+s2)){
            return map.get(s1+" "+s2);
        }
        boolean ans = false;
        for(int i=1;i<s1.length();i++){
            boolean x =help(s1.substring(0,i),s2.substring(0,i)) && help(s1.substring(i),s2.substring(i));
            boolean y = help(s1.substring(i),s2.substring(0,s2.length()-i)) && help(s1.substring(0,i),s2.substring(s2.length()-i));
            if(x || y){
                ans = true;
                break;
            }
        }
        map.put(s1+" "+s2,ans);
        return ans;
    }
}

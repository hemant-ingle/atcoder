import sys

sys.setrecursionlimit(10**7)

def frog_1(h, i, dp):
  if i==0: return 0
  if dp[i] != -1: return dp[i]
  jump1=abs(h[i] - h[i-1]) + frog_1(h, i-1, dp)
  jump2=float('inf')
  if i>1: jump2=abs(h[i] - h[i-2]) + frog_1(h, i-2, dp)
  dp[i]=min(jump1, jump2)
  return dp[i]

def main():
  n=int(input())
  h=list(map(int, input().split(' ')))
  dp=[-1] * n
  ans=frog_1(h,n-1,dp)
  print(ans)

if __name__=='__main__':
  main()
while True:
  try:
    s=input();
  except EOFError:
    break
  k1,k2,k3 = map(int,s.split())
  ans=k2-k1-1
  if(k3-k2-1>ans):
    ans=k3-k2-1
  print(ans)
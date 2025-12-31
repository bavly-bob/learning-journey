// beeramid
// https://www.codewars.com/kata/5a4d303f880385399b000001
// Your friend John is a bartender at a local bar. He has a lucrative side
// business building "beeramid"s - beer can pyramids - for parties. A beeramid
// is built by stacking cans in successive levels to form a pyramid shape.
// Returns number of complete beeramid levels
int beeramid(int bonus, double price)
{
  int can_number = (bonus / price), count = 0;
  
  while( can_number >= 0)
  {
    count ++;
    can_number -= count*count;
  }
  return count-1;
}

//Another solution that might be easier to read

int beeramid(int bonus, double price)
{
    if (bonus <= 0 || price <= 0)
        return 0;

    int cans = static_cast<int>(bonus / price);
    int level = 0;

    while (cans >= (level + 1) * (level + 1))
    {
        level++;
        cans -= level * level;
    }

    return level;
}
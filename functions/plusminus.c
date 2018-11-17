float plusminus ()
// Menghasilkan hasil penjumlahan dan pengurangan
{
  float x = timesdiv();
  if (FailedInput(x))
  {
    return (Fail);
  }
  else
  {
    while (*now == '+' || *now == '-')
    {
      char opr = *now;
      now++;
      float y = timesdiv();
      if (FailedInput(y))
      {
        return (Fail);
      }
      if (opr == '+')
      {
        x += y;
      }
      else
      {
        x -= y;
      }
    }
    return x;
  }
}

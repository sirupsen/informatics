import java.awt.*;
import java.console.*;

public class Wireless
{
  static Console c;

  public static void main (String[] args)
  {
    c = new Console ();
    TextInputFile f = new TextInputFile ("s5.5.in");

    // diff[0][c] holds the running total at row 0 and column c;
    // diff[r][c] where r>0 holds the difference
    // between the running totals at (row r,column c) and (row r-1,column c).
    int[] [] diff;

    int cols, rows, col, row, radius, bitrate, left, right;
    rows = f.readInt ();
    cols = f.readInt ();
    diff = new int [rows+1] [cols+1];

    for (int i = 0 ; i <= rows ; i++)
      for (int j = 0 ; j <= cols ; j++)
        diff [i] [j] = 0;

    int k = f.readInt ();
    for (int i = 0 ; i < k ; i++)
    {
      col = f.readInt ();
      row = f.readInt ();
      radius = f.readInt ();
      bitrate = f.readInt ();

      row--; 
      col--; //for zero-based indices

      //range of columns covered: the circle extends a number of columns in each direction equal to its radius,
      //but if it goes beyond the boundaries, then we don't consider those outside slices.
      for (int j = Math.max (0, col - radius) ; j <= Math.min (cols - 1, col + radius) ; j++)
      {
        // from the equation of the circle we calculate 
        // left, the first row in this column covered by this circle
        // right, the last row in this column covered by this circle.
        left = Math.max (0, row - (int) Math.sqrt (radius * radius - (col - j) * (col - j)));
        right = Math.min (rows - 1, row + (int) Math.sqrt (radius * radius - (col - j) * (col - j)));
        diff [left] [j] += bitrate;
        diff [right + 1] [j] -= bitrate;
      }
    }
    int best = 0;
    int count = 0;
    for (int i = 0 ; i < rows ; i++)
      for (int j = 0 ; j < cols ; j++)
      {
        //calculate the actual bitrate at (i,j) by adding
        if (i > 0)
          diff [i] [j] += diff [i - 1] [j]; 
        if (diff [i] [j] == best)
          count++;
        if (diff [i] [j] > best)
        {
          best = diff [i] [j];
          count = 1;
        }
      }
    c.println (best + "\n" + count);
  }
}

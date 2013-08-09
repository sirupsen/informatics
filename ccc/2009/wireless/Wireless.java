import java.io.IOException;
import static java.lang.System.*;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

public class Wireless
{
  static InputReader c;

  public static void main (String[] args)
  {
    InputStream inputStream = System.in;
    c = new InputReader(inputStream);

    // diff[0][c] holds the running total at row 0 and column c;
    // diff[r][c] where r>0 holds the difference
    // between the running totals at (row r,column c) and (row r-1,column c).
    int[] [] diff;

    int cols, rows, col, row, radius, bitrate, left, right;
    rows = c.readInt ();
    cols = c.readInt ();
    diff = new int [rows+1] [cols+1];

    for (int i = 0 ; i <= rows ; i++)
      for (int j = 0 ; j <= cols ; j++)
        diff [i] [j] = 0;

    int k = c.readInt ();
    for (int i = 0 ; i < k ; i++)
    {
      col = c.readInt ();
      row = c.readInt ();
      radius = c.readInt ();
      bitrate = c.readInt ();

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


    System.out.println("sup!");
    System.out.println(best + "\n" + count);
  }
}

class InputReader {
  private InputStream stream;
  private byte[] buf = new byte[1024];
  private int curChar;
  private int numChars;
  private SpaceCharFilter filter;

  public InputReader(InputStream stream) {
    this.stream = stream;
  }

  public int read() {
    if (numChars == -1)
      throw new InputMismatchException();
    if (curChar >= numChars) {
      curChar = 0;
      try {
        numChars = stream.read(buf);
      } catch (IOException e) {
        throw new InputMismatchException();
      }
      if (numChars <= 0)
        return -1;
    }
    return buf[curChar++];
  }

  public int readInt() {
    int c = read();
    while (isSpaceChar(c))
      c = read();
    int sgn = 1;
    if (c == '-') {
      sgn = -1;
      c = read();
    }
    int res = 0;
    do {
      if (c < '0' || c > '9')
        throw new InputMismatchException();
      res *= 10;
      res += c - '0';
      c = read();
    } while (!isSpaceChar(c));
    return res * sgn;
  }

  public boolean isSpaceChar(int c) {
    if (filter != null)
      return filter.isSpaceChar(c);
    return isWhitespace(c);
  }

  public static boolean isWhitespace(int c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
  }

  public interface SpaceCharFilter {
    public boolean isSpaceChar(int ch);
  }
}

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Lu {
    static float a[][], l[][], u[][], b[],sum,z[],x[];
    static int mp[];
    static int c = 0, row = 0;

    static void input() throws IOException {
        File file = new File("input.txt");

        BufferedReader br = new BufferedReader(new FileReader(file));
        String s;
        while ((s = br.readLine()) != null) {

            s = s.replaceAll("\\s", "");
            //System.out.println(s);
            int l = s.length();
            int i;
            for (i = 0; i < l; i++) {
                boolean value;
                int mul = 1;
                if (s.charAt(i) == '=')
                    break;
                if (s.charAt(i) == '+') {
                    mul = 1;
                    i++;
                   // System.out.println("+" + mul);
                }
                if (s.charAt(i) == '-') {
                    mul = -1;
                   // System.out.println("-" + mul);
                    i++;
                }
                int num = 0;
                while ((s.charAt(i) >= '0' && s.charAt(i) <= '9')) {
                    num = num * 10 + s.charAt(i) - 48;
                    //System.out.println("nmm " + num);
                    i++;
                }
                num = num * mul;
                //System.out.println("num " + num);
                if (mp[s.charAt(i)] == -1) {
                    mp[s.charAt(i)] = c++;
                }
                int col = mp[s.charAt(i)];
                if (num == 0) {
                    a[row][col] = mul;
                } else
                    a[row][col] = num;
               // System.out.println("value " + row + " " + col + " " + a[row][col]);

            }
            int bnum = 0;
            int mul = 1;
            for (; i < l; i++) {
                if (s.charAt(i) == '+') {
                    mul = 1;
                    i++;
                }
                if (s.charAt(i) == '-') {
                    mul = -1;
                    i++;
                }
                if (s.charAt(i) >= '0' && s.charAt(i) <= '9')
                    bnum = bnum * 10 + s.charAt(i) - 48;
            }
            b[row] = bnum*mul;
            row++;
        }
    }

    static void print() {
        int i, j;
        System.out.println("matrix:");
        for (i = 0; i < row; i++) {
            for (j = 0; j < c; j++) {
                System.out.print(a[i][j]+ " ");
            }
            System.out.println();
        }
        System.out.println("b:");
        for(i=0;i<row;i++)
        {
            System.out.println(b[i]);
        }
    }
    static void getCofactor(float mat[][], float temp[][], int p, int q, int n)
    {
        int i = 0, j = 0;

        // Looping for each element of the matrix
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                //  Copying into temporary matrix only those element
                //  which are not in given row and column
                if (row != p && col != q)
                {
                    temp[i][j++] = mat[row][col];

                    // Row is filled, so increase row index and
                    // reset col index
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    /* Recursive function for finding determinant of matrix.
       n is current dimension of mat[][]. */
    static float determinantOfMatrix(float mat[][], int n)
    {
        int D = 0; // Initialize result

        //  Base case : if matrix contains single element
        if (n == 1)
            return mat[0][0];

        float temp[][]=new float[20][20]; // To store cofactors

        int sign = 1;  // To store sign multiplier

        // Iterate for each element of first row
        for (int f = 0; f < n; f++)
        {
            // Getting Cofactor of mat[0][f]
            getCofactor(mat, temp, 0, f, n);
            D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
            // terms are to be added with alternate sign
            sign = -sign;
        }

        return D;
    }
    public static void main(String[] args) throws IOException {
        a = new float[20][20];
        l = new float[20][20];
        u = new float[20][20];
        b = new float[20];
        z=new float[20];
        x=new float[20];
        mp = new int[200];
        Arrays.fill(mp, -1);
        input();
        print();
        if(row!=c) {
            System.out.println("answer doesn't exist");
            return;
        }
        int n,i,k,j,p;
        n=row-1;
        float det=determinantOfMatrix(a,n);
        System.out.println("det "+det);
        File f = new File("Output.txt");
        FileOutputStream fos = new FileOutputStream(f);
        PrintWriter pw = new PrintWriter(fos);
        if(det==0.0) {
            System.out.println("answer doesn't exist and determinant is 0");
            return;
        }

        //********** LU decomposition *****/
        for(k=0; k<=n; k++)
        {
            u[k][k]=1;
            for(i=k; i<=n; i++)
            {
                sum=0;
                for(p=0; p<=k-1; p++)
                    sum+=l[i][p]*u[p][k];
                l[i][k]=a[i][k]-sum;
            }

            for(j=k+1; j<=n; j++)
            {
                sum=0;
                for(p=0; p<=k-1; p++)
                    sum+=l[k][p]*u[p][j];
                u[k][j]=(a[k][j]-sum)/l[k][k];
            }
        }
        //******** Displaying LU matrix**********/
        System.out.println("LU matrix :");
        System.out.println("L:");
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=n; j++)
                System.out.print(l[i][j]+" ");;
            System.out.println();
        }
        System.out.println("U:");
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=n; j++)
                System.out.print(u[i][j]+" ");
            System.out.println();
        }

        //***** FINDING Z; LZ=b*********/

        for(i=0; i<=n; i++)
        {
            //forward subtitution method
            sum=0;
            for(p=0; p<i; p++)
                sum+=l[i][p]*z[p];
            z[i]=(b[i]-sum)/l[i][i];
        }
        //********** FINDING X; UX=Z***********/

        for(i=n; i>=0; i--)
        {
            sum=0;
            for(p=n; p>i; p--)
                sum+=u[i][p]*x[p];
            x[i]=(z[i]-sum)/u[i][i];
        }
        //*********** DISPLAYING SOLUTION**************/
        System.out.println("Set of solution is");
        for(i=0; i<=n; i++)
            pw.write(""+x[i]+"\n");
        pw.flush();
        fos.close();
        pw.close();
    }
}

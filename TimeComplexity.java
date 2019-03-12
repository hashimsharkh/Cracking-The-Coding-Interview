import java.io.*;
//These are cracking the coding interview examples with me trying them out for myself and understanding them
public class TimeComplexity
{
	/*BinarySearch has time complexity of logn because each time it is going through the while loop we are down to searching n/2
	of the elements and we stop when we reach one.
	For eg.
	N=16 
	N=8
	N=4
	N=2
	N=1
	How many times did it take us to reach 1
	2^k=16
	log16=k */
	public static int binarySearch(int [] arr,int key)
	{
		int low=0;
		int high=arr.length-1;
		while(high>=low)
		{
			int mid=(high+low)/2;
			if(key>arr[mid])
				low = mid+1;
			else if(key==arr[mid])return mid;
			else high = mid-1;
		}	
		return -low-1;

	}
	//The algorithm runs in O(N) times as it goes through half of the array
	public static void reverse(int [] array)
	{
		for(int i=0;i<array.length/2;i++)
		{
			int other = array.length -i-1;
			int temp = array[i];
			array[i] = array[other];
			array[other]=temp;
		}
	}

	//This runs in O(sqrt(N)) time
	public static boolean isPrime(int n)
	{
		for(int i=2;i*i<=n;i++)
			if(n%i==0)
				return false;
		return true;
	}
	//This recursive function runs in O(N) times as the depth of the tree is N and the branches are 1
	//O(branches^depth) in recursive functions
	public static int factorial(int n)
	{
		if(n==0||n==1)
			return 1;
		return n*factorial(n-1);
	}
	//Runs in O(N^2) time as there are n numbers checked first if prime and then printed
	public static void allPrimes(int n)
	{
		int count=0;
		System.out.println("All the primes up to "+ n+ " are:");
		for(int i=2;i<=n;i++)

			if(isPrime(i)==true)
				{
					System.out.print(i+ " ");
					count++;
				}
		System.out.println();
		System.out.println("There are "+ count +" primes from 2 to " +n);
	}
	public static void permutation(String str)
	{
		permutation(str,"");
	}
		public static void permutation(String str,String prefix)
	{
		if(str.length()==0)
			System.out.println(prefix);
		else
			for(int i=0;i<str.length();i++)
			{
				String rem = str.substring(0,i) +str.substring(i+1);
				permutation(rem,prefix+str.charAt(i));
			}
	}
	//Runs in O(2^n) time
	public static int fib(int n)
	{
		if(n<=0)
			return 0;
		else if(n==1)
			return 1;
		return fib(n-1)+fib(n-2);
	}
	/*As n is varying each step takes 2^n time 
	and then the sum of that is 2^n+1 using geometric series
	very terrible algo */
	/*public static void allFib(int n)
	{
		System.out.print("The fibonacci numbers until " + n);
		System.out.print(" are: ");
		for(int i=0;i<n;i++)
			System.out.print(fib(i) + " ");
		System.out.println();

	}*/
	//MEMOISATION-IMPORTANT REDUCES TIME COMPLEXITY SIGNIFICANTLY AS IT SAVES PREVIOUS VALUES INTO THE MEMORY
	public static void allFib(int n)
	{
		int [] memo = new int[n+1];
		for(int i=0;i<n;i++)
			System.out.println(i+" "+ fib(i,memo));
	}
	public static int fib(int n,int [] memo)
	{
		if(n<=0) return 0;
		else if(n==1) return 1;
		else if(memo[n]>0) return memo[n];

		memo[n]=fib(n-1,memo)+fib(n-2,memo);
		return memo[n];
	}
	//Runs at a 
	public static int powersOf2(int n)
	{
		if(n<1)
			return 0;
		else if(n==1)
		{
			System.out.println(1);
			return 1;
		}	
		else
		{
			int prev =powersOf2(n/2);
			int curr = prev*2;
			System.out.println(curr);
			return curr;
		}
		
	}


	//ADDITIONAL PROBLEMS- find the runtime
	
	//Q1- my thoughts before calculating runtime. The author of the book is calculating the product using a form of repeated
	//Addition.
	//Calculating the runtime:
	//There is one for loop that runs b amount of times and the summation is O(1) since its just a constant time statement
	//Therefore the runtime of Q1 is O(b) as the for loop iterates through b
	public static int product(int a,int b)
	{
		int sum=0;
		for(int i=0;i<b;i++)
			sum+=a;
		
		return sum;
	}

	//Q2- The following code computes a^b and i copied it directly from the book
	//Only positive exponents are allowed
	//This is done recursively as it seems where the base case is when the exponent is 0 (a can not be 0 also)
	//This is O(b) as the recursive code iterates through b calls since it subtracts one at each level
	public static int power(int a,int b)
	{
		if(b<0)
			return 0;//error
		else if(b==0)
			return 1;
		else
			return a*power(a,b-1);
	}

	//Q3- Another mathematical operation and this computes a mod b using euclidean algorithm
	//This is just simply O(1) as it is doing a constant amount of work
	public static int mod(int a,int b)
	{
		if(b<=0)
			return -1;
		int div = a/b;
		return a-div*b;
	}

	//Q4- Integer division is performed by the following code(a and b are positive)
	//As observed one for loop that iterates through a/b times
	//Therefore O(a/b) is the runtime
	public static int div(int a,int b)
	{
		int count=0;
		int sum=b;
		while(sum<=a)
		{
			sum+=b;
			count++;
		}
		return count;
	}

	//Q5- The following code computes the integer square root of a number. If the number is not a perfect square root then
	//It returns -1. This is done by successive guessing.If n is 100 it first guesses 50. Too high? Try something lower -halfway 
	//between 1 and 50
	//This runs at O(log n) as it is basically doing a binary search to find the square root 
	public static int sqrt (int n)
	{
		return sqrt_helper(n,1,n);
	}

	public static int sqrt_helper(int n,int min, int max)
	{
		if(max<min) return -1; //No square root

		int guess= (min+max)/2;
		if(guess*guess==n)return guess;
		else if(guess*guess<n)
			return sqrt_helper(n,guess+1,max);
		else return sqrt_helper(n,min,guess-1);
	}

	//Q6- The following code computes the integer square root of a number like Q5 but this time it does this by trying
	//incrasingly large numbers
	//The for loop iterates square root n times therefore
	//The runtime is O(sqrt(n))
	public static int squareRoot(int n)
	{
		for(int guess=1;guess*guess<=n;guess++)
			if(guess*guess==n)return guess;
		return -1;
	}

	//Q7 and Q8- HAVENT STUDIED BINARY SEARCH TREES YET
	
	//Q9-The appendToNew method appends a value to an array by creating a new, longer array and returning the longer array
	//You've used the appendToNew method to create a copyArray function that repeatedly calls appendToNew. How long does 
	//Copying an array take
	//Basically, what is happening according to my understanding is you start with an array called copy of no size then each 
	//value in array is copied starting with one copy then 2 copies then 3....
	//The work done is the sum of the natural numbers from 1 to n, which is n(1+n)/2 
	//Therefore the order is O(n^2)
	public static int [] copyArray(int [] array)
	{
		int [] copy =new int[0];
		for(int value:array)
		{
			copy = appendToNew(copy,value);
		}
		return copy;
	}
	public static int [] appendToNew(int [] array,int value)
	{
		int [] bigger = new int[array.length+1];
		for(int i=0;i<array.length;i++)
			bigger[i] = array[i];
		//Add new element
		bigger[bigger.length-1]=value;
		return bigger;
	}
	public static void main(String[] args)
	{
		int arr[]={1,2,3,4,5,6};
		allPrimes(100);
		powersOf2(65);
		permutation("Alyssa");
	}
}
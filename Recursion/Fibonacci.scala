import scala.io.StdIn.readInt

object Solution {
    
     def fibonacci(x:Int):Int = {
          
		// Fill Up this function body
        // You can add another function as well, if required
        if(x<=1)
            return 0;
        else if(x ==2)
            return 1;
        return fibonacci(x-1) + fibonacci(x-2);
    }
     

    def main(args: Array[String]) {
         /** This will handle the input and output**/
         println(fibonacci(readInt()))

    }
}

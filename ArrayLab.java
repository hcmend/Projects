import java.util.Arrays;

/**
 * Name: Hailey Mendenhall
 * Date: January 24
 * Purpose: The purpose of this lab is to show how to change arrays and display that other methods change the array of the main method.
 * It also displays how we can print out an array in a simple format.
 */
public class ArrayLab {
    /**
     * The main method of this program is what creates the original arrays
     * and then passes the result of the plusOne method into the printFormattedArray method.
     */
    public static void main(String[] args) {
        // should become {1,2,4} after call to plusOne
        int[] testArray1 = {1,2,3};        
        printFormattedArray(plusOne(testArray1));

        // should become {4,3,2,2} after call to plusOne
        int[] testArray2 = {4,3,2,1};        
        printFormattedArray(plusOne(testArray2));

        // should become {9,0,0} after call to plusOne
        int[] testArray3 = {8,9,9};         
        printFormattedArray(plusOne(testArray3));

        // should become {1,0} after call to plusOne
        int[] testArray4 = {9};        
        printFormattedArray(plusOne(testArray4));

        // should become {1,0,0,0} after call to plusOne
        int[] testArray5 = {9,9,9};        
        printFormattedArray(plusOne(testArray5));
    }
    /**
     * The plusOne method is what alters the array so that if you reas the elemetns like a singular number, the number is
     * increased by one. This then returns the altered array or a new array to the main method.
     */
    public static int[] plusOne(int[] digits) {
        if (digits[digits.length -1] != 9){
            digits[digits.length -1] += 1;
            return digits;
        }
        boolean allNine = true;
        for (int i = 0; i < digits.length; i++){
            if (digits[i] != 9){
                allNine = false;
            }
        }
        if (!allNine){
            for (int k = digits.length - 1; k >= 0;  k--){
                if(digits[k] == 9){
                    digits[k] = 0;
                }else {                    
                    digits[k] += 1;
                    return digits;
                }
            }
        }
        if (allNine){
            int[] newArray = Arrays.copyOf(digits, digits.length + 1);
            newArray[0] = 1;
            for(int j = 1; j < newArray.length; j++){
                newArray[j] = 0;
            }
            return newArray;
        }    
        
        
        return null;
    }
    /**
     * This method is taking the array from the plusOne method and printing it in a simple format that is easy to understand.      * 
     */
    public static void printFormattedArray(int[] arr) {
        System.out.println(Arrays.toString(arr));
    }

}
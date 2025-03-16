import java.util.Arrays;
public class code {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int ans;
        Arrays.sort(fruits);
        Arrays.sort(baskets);
        int i = 0, j = 0;
        ans = 0;
        while (i < fruits.length && j < baskets.length) {
            if (fruits[i] <= baskets[i]) {
                ans++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
}

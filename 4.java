public class Problem4 {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] arr = new int[(nums1.length + nums2.length)/2 + 1];
        int tot, x = 0, y = 0;
        tot = nums1.length + nums2.length;
        for (int i = 0; i < arr.length; i++){
            if (x == nums1.length){
                arr[i] = nums2[y];
                y++;
            }
            else if (y == nums2.length){
                arr[i] = nums1[x];
                x++;
            }
            else if (x < nums1.length && nums1[x] <= nums2[y]){
                arr[i] = nums1[x];
                x++;
            }
            else if (y < nums2.length && nums1[x] >= nums2[y]){
                arr[i] = nums2[y];
                y++;
            }
        }
        if (tot == 1)
            return arr[0];
        else if (tot == 2)
            return (arr[0] + arr[1]) / 2.0;
        return tot % 2 == 0 ? 
            (arr[arr.length-1] + arr[arr.length-2]) / 2.0: arr[arr.length-1];
    }
}
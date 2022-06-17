Smallest Rectangle Enclosing Black Pixels






public int minArea(char[][] image, int x, int y) {
       
        if(image == null || image.length < 1
           || x < 0 || x >= image.length
            || y < 0 || y >= image[0].length) return -1;

        int leftMostCol = findBoarder(image, y, true, false);
        int rightMostCol = findBoarder(image, y, false, false);
        int upMostRow = findBoarder(image, x, true, true);
        int downMostRow = findBoarder(image, x, false, true);

        return (rightMostCol - leftMostCol + 1) * (downMostRow - upMostRow + 1);
    }

    
    private int findBoarder(char[][] image, int i, boolean findInMinPart, boolean checkInRow) {
        int start = findInMinPart ? 0 : i;
        int end = findInMinPart ? i : (checkInRow ? image.length - 1 : image[0].length - 1);

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;

            if ((findInMinPart && hasBlackPixel(image, mid, checkInRow)) ||
                    !findInMinPart && !hasBlackPixel(image, mid, checkInRow)) {
                end = mid;
            }

            if ((findInMinPart && !hasBlackPixel(image, mid, checkInRow)) ||
                    !findInMinPart && hasBlackPixel(image, mid, checkInRow)) {
                start = mid;
            }
        }

        return findInMinPart ?
                (hasBlackPixel(image, start, checkInRow) ? start : end) :
                (hasBlackPixel(image, end, checkInRow) ? end : start);
    }

  
    private boolean hasBlackPixel(char[][] image, int i, boolean checkRow) {
        int n = image.length;
        int m = image[0].length;
        if (checkRow) {
            for(int col = 0; col < m; col++) {
                if(image[i][col] == '1') return true;
            }
        } else {
            for (int row = 0; row < n; row++) {
                if(image[row][i] == '1') return true;
            }
        }

        return false;
    }
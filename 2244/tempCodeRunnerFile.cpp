if (remainder == 1) {
            remainder = count % 2;
            cout << remainder << endl;
            if (remainder == 0) {
                res += count / 2;
            } else {
                return -1;
            }
        } else {
            res += count / 3;
            res += remainder / 2;
        }
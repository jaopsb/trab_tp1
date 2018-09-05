    string credit_card;
    cout << "enter the identification number" << endl;
    cin >> credit_card;

    // store the digits
    for (int i = 0 ; i < digits ; i ++ ) {
        Acc_num[i] = credit_card[i];
    }

    for (int i = 0 ; i <= (digits - 1) ; i ++ ) {
        Acc_num[i] -= 48;
    }

    // Double every other
    for (int i = 1 ; i <=digits ; i ++) {
        if (i % 2 == 0) {
            Acc_num[i-1] =  2 * Acc_num[i-1];
        } else {
            Acc_num[i-1] = Acc_num [i-1];
        }
    }

    //Sum digits
    for (int i = 1 ; i <= digits ; i ++ ) {
        if (Acc_num[i-1] > 9 && i % 2 == 0) {
            int mod = Acc_num[i-1] % 10 ;
            Acc_num[i-1]  =  1 + mod ;
        } else {
        Acc_num[i-1] = Acc_num[i-1];
        }
    }

    // the sum
    for (int i = 0 ; i <= (digits - 1) ; i ++ ) {
        shuma += Acc_num[i];
    }

    if (shuma % 10 == 0) {
        cout << "\nthis number is valid" << endl;
    } else {
        cout << "\nthis number is invalid" << endl;
    }
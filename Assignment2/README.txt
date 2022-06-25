hello, this is the solution folder for assignment-2
...........................................................................................................
metacoinloan_system.sol contains the code required for the task.
...........................................................................................................
metacoinloan_system is a smart contract through which the owner of the contract can keep a record of his loans and settle them accordingly.

the system has mainly 7 functions which are :-

1) reqLoan: it is a fuction through which a creditor can demand his loan ammount back. the principle amount, rate, and time will get feeded in the system for later use.
2) sendCoin: it is a function through which we can send coins to desired addresses. it is used in the functioning of other functions.
3) settleDues: it can be used by owner to settle dues to a particular address entered.
4) getBalance: it can be used to check balance of a account.
5) getOwnerBalance: it calls the balance of owner.
6) getCompundInterest: it calculates the compound interest for the principle, rate and time.
7) ViewDues: it shows the owner the dues of a particular address.

there are some other internal function also like mulDiv and add, which are used in other functions
............................................................................................................

these public functions are categorised into pure, view and normal functions.
view functions can read data outside the function but cant modify it.  
pure functions cannot read as well modify any data outside the function.
normal function just contain public in them, they do have these kind of restrictions as such.
............................................................................................................. 
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int t, y;
int anss[] = {12
, 23
, 34
, 45
, 56
, 67
, 78
, 89
, 123
, 234
, 345
, 456
, 567
, 678
, 789
, 910
, 1011
, 1112
, 1213
, 1234
, 1314
, 1415
, 1516
, 1617
, 1718
, 1819
, 1920
, 2021
, 2122
, 2223
, 2324
, 2345
, 2425
, 2526
, 2627
, 2728
, 2829
, 2930
, 3031
, 3132
, 3233
, 3334
, 3435
, 3456
, 3536
, 3637
, 3738
, 3839
, 3940
, 4041
, 4142
, 4243
, 4344
, 4445
, 4546
, 4567
, 4647
, 4748
, 4849
, 4950
, 5051
, 5152
, 5253
, 5354
, 5455
, 5556
, 5657
, 5678
, 5758
, 5859
, 5960
, 6061
, 6162
, 6263
, 6364
, 6465
, 6566
, 6667
, 6768
, 6789
, 6869
, 6970
, 7071
, 7172
, 7273
, 7374
, 7475
, 7576
, 7677
, 7778
, 7879
, 7980
, 8081
, 8182
, 8283
, 8384
, 8485
, 8586
, 8687
, 8788
, 8889
, 8910
, 8990
, 9091
, 9192
, 9293
, 9394
, 9495
, 9596
, 9697
, 9798
, 9899
, 12345
, 23456
, 34567
, 45678
, 56789
, 78910
, 91011
, 99100
, 100101
, 101102
, 101112
, 102103
, 103104
, 104105
, 105106
, 106107
, 107108
, 108109
, 109110
, 110111
, 111112
, 111213
, 112113
, 113114
, 114115
, 115116
, 116117
, 117118
, 118119
, 119120
, 120121
, 121122
, 121314
, 122123
, 123124
, 123456
, 124125
, 125126
, 126127
, 127128
, 128129
, 129130
, 130131
, 131132
, 131415
, 132133
, 133134
, 134135
, 135136
, 136137
, 137138
, 138139
, 139140
, 140141
, 141142
, 141516
, 142143
, 143144
, 144145
, 145146
, 146147
, 147148
, 148149
, 149150
, 150151
, 151152
, 151617
, 152153
, 153154
, 154155
, 155156
, 156157
, 157158
, 158159
, 159160
, 160161
, 161162
, 161718
, 162163
, 163164
, 164165
, 165166
, 166167
, 167168
, 168169
, 169170
, 170171
, 171172
, 171819
, 172173
, 173174
, 174175
, 175176
, 176177
, 177178
, 178179
, 179180
, 180181
, 181182
, 181920
, 182183
, 183184
, 184185
, 185186
, 186187
, 187188
, 188189
, 189190
, 190191
, 191192
, 192021
, 192193
, 193194
, 194195
, 195196
, 196197
, 197198
, 198199
, 199200
, 200201
, 201202
, 202122
, 202203
, 203204
, 204205
, 205206
, 206207
, 207208
, 208209
, 209210
, 210211
, 211212
, 212213
, 212223
, 213214
, 214215
, 215216
, 216217
, 217218
, 218219
, 219220
, 220221
, 221222
, 222223
, 222324
, 223224
, 224225
, 225226
, 226227
, 227228
, 228229
, 229230
, 230231
, 231232
, 232233
, 232425
, 233234
, 234235
, 234567
, 235236
, 236237
, 237238
, 238239
, 239240
, 240241
, 241242
, 242243
, 242526
, 243244
, 244245
, 245246
, 246247
, 247248
, 248249
, 249250
, 250251
, 251252
, 252253
, 252627
, 253254
, 254255
, 255256
, 256257
, 257258
, 258259
, 259260
, 260261
, 261262
, 262263
, 262728
, 263264
, 264265
, 265266
, 266267
, 267268
, 268269
, 269270
, 270271
, 271272
, 272273
, 272829
, 273274
, 274275
, 275276
, 276277
, 277278
, 278279
, 279280
, 280281
, 281282
, 282283
, 282930
, 283284
, 284285
, 285286
, 286287
, 287288
, 288289
, 289290
, 290291
, 291292
, 292293
, 293031
, 293294
, 294295
, 295296
, 296297
, 297298
, 298299
, 299300
, 300301
, 301302
, 302303
, 303132
, 303304
, 304305
, 305306
, 306307
, 307308
, 308309
, 309310
, 310311
, 311312
, 312313
, 313233
, 313314
, 314315
, 315316
, 316317
, 317318
, 318319
, 319320
, 320321
, 321322
, 322323
, 323324
, 323334
, 324325
, 325326
, 326327
, 327328
, 328329
, 329330
, 330331
, 331332
, 332333
, 333334
, 333435
, 334335
, 335336
, 336337
, 337338
, 338339
, 339340
, 340341
, 341342
, 342343
, 343344
, 343536
, 344345
, 345346
, 345678
, 346347
, 347348
, 348349
, 349350
, 350351
, 351352
, 352353
, 353354
, 353637
, 354355
, 355356
, 356357
, 357358
, 358359
, 359360
, 360361
, 361362
, 362363
, 363364
, 363738
, 364365
, 365366
, 366367
, 367368
, 368369
, 369370
, 370371
, 371372
, 372373
, 373374
, 373839
, 374375
, 375376
, 376377
, 377378
, 378379
, 379380
, 380381
, 381382
, 382383
, 383384
, 383940
, 384385
, 385386
, 386387
, 387388
, 388389
, 389390
, 390391
, 391392
, 392393
, 393394
, 394041
, 394395
, 395396
, 396397
, 397398
, 398399
, 399400
, 400401
, 401402
, 402403
, 403404
, 404142
, 404405
, 405406
, 406407
, 407408
, 408409
, 409410
, 410411
, 411412
, 412413
, 413414
, 414243
, 414415
, 415416
, 416417
, 417418
, 418419
, 419420
, 420421
, 421422
, 422423
, 423424
, 424344
, 424425
, 425426
, 426427
, 427428
, 428429
, 429430
, 430431
, 431432
, 432433
, 433434
, 434435
, 434445
, 435436
, 436437
, 437438
, 438439
, 439440
, 440441
, 441442
, 442443
, 443444
, 444445
, 444546
, 445446
, 446447
, 447448
, 448449
, 449450
, 450451
, 451452
, 452453
, 453454
, 454455
, 454647
, 455456
, 456457
, 456789
, 457458
, 458459
, 459460
, 460461
, 461462
, 462463
, 463464
, 464465
, 464748
, 465466
, 466467
, 467468
, 468469
, 469470
, 470471
, 471472
, 472473
, 473474
, 474475
, 474849
, 475476
, 476477
, 477478
, 478479
, 479480
, 480481
, 481482
, 482483
, 483484
, 484485
, 484950
, 485486
, 486487
, 487488
, 488489
, 489490
, 490491
, 491492
, 492493
, 493494
, 494495
, 495051
, 495496
, 496497
, 497498
, 498499
, 499500
, 500501
, 501502
, 502503
, 503504
, 504505
, 505152
, 505506
, 506507
, 507508
, 508509
, 509510
, 510511
, 511512
, 512513
, 513514
, 514515
, 515253
, 515516
, 516517
, 517518
, 518519
, 519520
, 520521
, 521522
, 522523
, 523524
, 524525
, 525354
, 525526
, 526527
, 527528
, 528529
, 529530
, 530531
, 531532
, 532533
, 533534
, 534535
, 535455
, 535536
, 536537
, 537538
, 538539
, 539540
, 540541
, 541542
, 542543
, 543544
, 544545
, 545546
, 545556
, 546547
, 547548
, 548549
, 549550
, 550551
, 551552
, 552553
, 553554
, 554555
, 555556
, 555657
, 556557
, 557558
, 558559
, 559560
, 560561
, 561562
, 562563
, 563564
, 564565
, 565566
, 565758
, 566567
, 567568
, 568569
, 569570
, 570571
, 571572
, 572573
, 573574
, 574575
, 575576
, 575859
, 576577
, 577578
, 578579
, 579580
, 580581
, 581582
, 582583
, 583584
, 584585
, 585586
, 585960
, 586587
, 587588
, 588589
, 589590
, 590591
, 591592
, 592593
, 593594
, 594595
, 595596
, 596061
, 596597
, 597598
, 598599
, 599600
, 600601
, 601602
, 602603
, 603604
, 604605
, 605606
, 606162
, 606607
, 607608
, 608609
, 609610
, 610611
, 611612
, 612613
, 613614
, 614615
, 615616
, 616263
, 616617
, 617618
, 618619
, 619620
, 620621
, 621622
, 622623
, 623624
, 624625
, 625626
, 626364
, 626627
, 627628
, 628629
, 629630
, 630631
, 631632
, 632633
, 633634
, 634635
, 635636
, 636465
, 636637
, 637638
, 638639
, 639640
, 640641
, 641642
, 642643
, 643644
, 644645
, 645646
, 646566
, 646647
, 647648
, 648649
, 649650
, 650651
, 651652
, 652653
, 653654
, 654655
, 655656
, 656657
, 656667
, 657658
, 658659
, 659660
, 660661
, 661662
, 662663
, 663664
, 664665
, 665666
, 666667
, 666768
, 667668
, 668669
, 669670
, 670671
, 671672
, 672673
, 673674
, 674675
, 675676
, 676677
, 676869
, 677678
, 678679
, 678910
, 679680
, 680681
, 681682
, 682683
, 683684
, 684685
, 685686
, 686687
, 686970
, 687688
, 688689
, 689690
, 690691
, 691692
, 692693
, 693694
, 694695
, 695696
, 696697
, 697071
, 697698
, 698699
, 699700
, 700701
, 701702
, 702703
, 703704
, 704705
, 705706
, 706707
, 707172
, 707708
, 708709
, 709710
, 710711
, 711712
, 712713
, 713714
, 714715
, 715716
, 716717
, 717273
, 717718
, 718719
, 719720
, 720721
, 721722
, 722723
, 723724
, 724725
, 725726
, 726727
, 727374
, 727728
, 728729
, 729730
, 730731
, 731732
, 732733
, 733734
, 734735
, 735736
, 736737
, 737475
, 737738
, 738739
, 739740
, 740741
, 741742
, 742743
, 743744
, 744745
, 745746
, 746747
, 747576
, 747748
, 748749
, 749750
, 750751
, 751752
, 752753
, 753754
, 754755
, 755756
, 756757
, 757677
, 757758
, 758759
, 759760
, 760761
, 761762
, 762763
, 763764
, 764765
, 765766
, 766767
, 767768
, 767778
, 768769
, 769770
, 770771
, 771772
, 772773
, 773774
, 774775
, 775776
, 776777
, 777778
, 777879
, 778779
, 779780
, 780781
, 781782
, 782783
, 783784
, 784785
, 785786
, 786787
, 787788
, 787980
, 788789
, 789790
, 790791
, 791792
, 792793
, 793794
, 794795
, 795796
, 796797
, 797798
, 798081
, 798799
, 799800
, 800801
, 801802
, 802803
, 803804
, 804805
, 805806
, 806807
, 807808
, 808182
, 808809
, 809810
, 810811
, 811812
, 812813
, 813814
, 814815
, 815816
, 816817
, 817818
, 818283
, 818819
, 819820
, 820821
, 821822
, 822823
, 823824
, 824825
, 825826
, 826827
, 827828
, 828384
, 828829
, 829830
, 830831
, 831832
, 832833
, 833834
, 834835
, 835836
, 836837
, 837838
, 838485
, 838839
, 839840
, 840841
, 841842
, 842843
, 843844
, 844845
, 845846
, 846847
, 847848
, 848586
, 848849
, 849850
, 850851
, 851852
, 852853
, 853854
, 854855
, 855856
, 856857
, 857858
, 858687
, 858859
, 859860
, 860861
, 861862
, 862863
, 863864
, 864865
, 865866
, 866867
, 867868
, 868788
, 868869
, 869870
, 870871
, 871872
, 872873
, 873874
, 874875
, 875876
, 876877
, 877878
, 878879
, 878889
, 879880
, 880881
, 881882
, 882883
, 883884
, 884885
, 885886
, 886887
, 887888
, 888889
, 888990
, 889890
, 890891
, 891011
, 891892
, 892893
, 893894
, 894895
, 895896
, 896897
, 897898
, 898899
, 899091
, 899900
, 900901
, 901902
, 902903
, 903904
, 904905
, 905906
, 906907
, 907908
, 908909
, 909192
, 909910
, 910911
, 911912
, 912913
, 913914
, 914915
, 915916
, 916917
, 917918
, 918919
, 919293
, 919920
, 920921
, 921922
, 922923
, 923924
, 924925
, 925926
, 926927
, 927928
, 928929
, 929394
, 929930
, 930931
, 931932
, 932933
, 933934
, 934935
, 935936
, 936937
, 937938
, 938939
, 939495
, 939940
, 940941
, 941942
, 942943
, 943944
, 944945
, 945946
, 946947
, 947948
, 948949
, 949596
, 949950
, 950951
, 951952
, 952953
, 953954
, 954955
, 955956
, 956957
, 957958
, 958959
, 959697
, 959960
, 960961
, 961962
, 962963
, 963964
, 964965
, 965966
, 966967
, 967968
, 968969
, 969798
, 969970
, 970971
, 971972
, 972973
, 973974
, 974975
, 975976
, 976977
, 977978
, 978979
, 979899
, 979980
, 980981
, 981982
, 982983
, 983984
, 984985
, 985986
, 986987
, 987988
, 988989
, 989990
, 990991
, 991992
, 992993
, 993994
, 994995
, 995996
, 996997
, 997998
, 998999
, 1234567};

int ans;

void solve(){
  cin >> y;
  for(int i=0; i<1114; i++){
    if(y < anss[i]){
      ans = anss[i];
      return;
    }
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> t;
  for(int i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << ans << endl;
  }
}
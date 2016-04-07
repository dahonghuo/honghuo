/*
 * CAnony_tests.cpp
 *
 *  Created on: 2015-04-24
 *      Author: frank
 */

#include "CIpo_tests.h"
#include "CycleTestManger.h"
#include <boost/assign/list_of.hpp>
#include "json/json_spirit_utils.h"
#include "json/json_spirit_value.h"
#include "json/json_spirit_reader.h"
using namespace std;
using namespace boost;
using namespace boost::assign;
using namespace json_spirit;

typedef struct user{
	unsigned char address[35];
	int64_t money;
	int64_t freemoney;
	int64_t freeMothmoney;
	user()
	{
		memset(address,0,35);
		money = 0;
		freemoney = 0;
		freeMothmoney = 0;
	}
	IMPLEMENT_SERIALIZE
	(
			for(int i = 0;i < 35;i++)
			READWRITE(address[i]);
			READWRITE(money);
			READWRITE(freemoney);
			READWRITE(freeMothmoney);
	)
}IPO_USER;

typedef struct tagdddd{
	const char * pAddress;
	int64_t nMoney;
}IPO_DATA;

//const int64_t totalSendMoney = 10825192381120926; //二期IPO第一批发币总额
//const int64_t totalSendMoney =  2711374031363492; //二期IPO第二批发币总额
//const int64_t totalSendMoney =  2677621584404177; //二期IPO第三批发币总额
//const int64_t totalSendMoney = 19164400000000000;   //一期IPO第一批总额
//const int64_t totalSendMoney =    4913960000000000;   //一期IPO第二批总额
//const int64_t totalSendMoney =    17567366666666608;     /// 一期IPO11个月冻结金额的钱
//const int64_t totalSendMoney =    20000000000000000;     /// 官方冻结金额总额

//const int64_t totalSendMoney = 200000000*COIN;   	//开发团队5个月锁仓总金额
//const int64_t totalSendMoney = 800000000*COIN;    //运营团队10个月锁仓总金额
//const int64_t totalSendMoney = 320000000*COIN;   //一期IPO20个月锁仓总金额
const int64_t totalSendMoney = 50000*COIN;       //测试提现
//const string strAppId = "1471-1";                //测试环境开发团队冻结应用ID   5月
//const string strAppId = "1353-1";                //测试环境运营团队冻结应用ID   10月 此ID可能有问题
//const string strAppId = "4169-1";                  //测试环境一期众筹冻结应用ID   20月
const string strAppId = "4358-1";                //测试环境测试提现功能冻结应用ID 10分钟 20期
//const string strAppId = "9750-1";                //测试环境二期众筹冻结应用ID   30月
//const string strAppId = "9756-1";                //测试环境交易返回冻结应用ID   100月


#define freeze_count 20
#define max_user   300 //100


IPO_DATA arrayData[]=
{
//		{"DpqbJLPkBrevxYKpZYAbQp6DJSHzHFiruf",	10000000000000000}, //
//		{"DsSyKYzYBSgyEggq8o6SVD4DnPzETVbaUe",	10000000000000000},
//		{"DmtzzT99HYUGAV6ejkWTWXF8pcYXtkpU4g", -1517878787878782}
//		{"DpqbJLPkBrevxYKpZYAbQp6DJSHzHFiruf", 10000}


/*		{"DUf8eyPR6XdNrzryd5J61HbKHvSMsMB6AG",	241805652793523   },
		{"Dppfoo66R2JnHyGaYHDVAQeEh4VNycv5Jw",	237895142961445   },
		{"DagEgfLcoBch6QHjBHZwGv3d8a7yNUZvq4",	101203390268344   },
		{"DeJ7imC7baVdsU3d9uvwGPXTSQ8xKVtXAa",	18856210281645    },
		{"DkE7fomsnLLZ2ZkvYFjTFhYuYgLQpeWAxH",	32240753705803    },
		{"Dd8Gf1jN89aUGX4dArUzxircV2b7uszfTn",	31717534410533    },
		{"DaZpxWaHaeqNGZRyeDomyNrmQ4oZyiiHu9",	156095846904437   },
		{"DdNwyLCar7cVYjQRgziuEvfrFmbU2JpMNY",	609764184032080   },
		{"DdqwdjxAL1p6ZfmkUKbwdyTVFSTm5Np8CC",	15609584690444    },
		{"DW4pTBfyGjmZTGtkcGNtzhxXRHmf7FbYMv",	15490516249954    },
		{"DsiQo7FfWx7oGchPmARQcKqeTdy1ZRNjc6",	63459923086691    },
		{"Do5jPqr8G9iG3P8CcqtAZocaV6SwDzNAUu",	153011360252777   },
		{"DZHn8N2gkDTh3wYSzKjwhbgbyTeYz7KpjN",	55248479022527    },
		{"DayfBVQ8qD6raMLVKhDCoKJzuRjBRe5ZJj",	494068063432120   },
		{"DmxSaF392Ud9ZpY52zsgc6NyvaUz8omFf4",	173341686391992   },
		{"Dp9LVZSX2CTREytdYkUCzP8iZjKRK63ckf",	9435968447862     },
		{"Di8U4vztuxxFnqwR4RzDZ1HbDV9dqy2oiA", 	23100000000000    },
		{"DYMaTEBoYtuFXGPsjMtdb7wr5xEVqETzyW",	68037287472000    },
		{"De6fbY6YhXLdwYxnHtn5UaLz5sv3AnYgAF",	89040000000000    },
		{"DYU1ACJNFRMiJ8hjmJrTPWPsEmNrmPAYL5",	44520000000000    },
		{"Dc6ChgzzEHyWWgPYM7WFVfebo33naQL67n",	43680000000000    }
*/
		/*=================红火币开发团队测试==================================
		{"hMfb4tyQubHPLMqchiEQrmW4JaD7wQbWoc", 20000000000000000}*/
		/*=================红火币一期IPO测试=================================*/
/*		{"hd8vxfXqxW7dcbaZSS7hYn9gkxY4Vs9bXL",    2000000 * COIN   },
		{"hGrsutJkZ4uhwy1EwDp4MHYsfVCRpqgULZ",   4000000 * COIN    },
		{"hcvBjoAtXrB4AgRufigriNKfZFYP4bKSTT",   4000000 * COIN    },
		{"hKGMxbyi129MjupA4PrJTSrtekqvM3GLcG",   2000000 * COIN    },
		{"hbesadgNYvdTmJj4tYt6xrGKmWT2bZSqmh",   6000000 * COIN    },
		{"hJhbcJYVrrM9rY4Bk3Gg8Ut5Tz1V83MyXi",   20000000 * COIN   },
		{"he8jPX5DDYfS5MWgLTFX4pt8tNCygraL6W",   4000000 * COIN    },
		{"hYDAUmSsFNEEWrxkJ2EMr6tjJ6QFW9udjp",   2000000 * COIN    },
		{"hT8EEsAUZLMGczn9K9epvLVzrvNs5n6ngG",   2000000 * COIN    },
		{"hSHVoWcpDzNpDtamK2T7vj8BABCRqGo1Ae",   2000000 * COIN    },
		{"hbFgmohzWuSTkrz4aohxQaG73ehWXCeBXU",   4000000 * COIN    },
		{"hWUPHdQ7CjEyAT9CzqhfJkzMMYeMBDQWV5",   2000000 * COIN    },
		{"hZRfQNcB6WPkt3CtsNrBk3eVKc1mp6BFAJ",   4000000 * COIN    },
		{"hVFwrZdquyBQy5KZPH1xamf8PNBQ3dttAp",   20000000 * COIN   },
		{"hdzTarZn9ZU6YXaRvt2JS76TeK3P7zKsSG",   2000000 * COIN    },
		{"hNXBm5TrGKMawfQhC9Ako825uc2SUGJkz4",   2000000 * COIN    },
		{"hHAfUB9XexqTEiJWEG9xniCMiX5moFRFEx",   2000000 * COIN    },
		{"hatY61bfhza9q3cpWKnudCF6VtXexxPbXE",   4000000 * COIN    },
		{"hFajaWfKQgZfSbfAqpzVPE6N4mJk82WjE6",   4000000 * COIN    },
		{"hZHqtdgvRzZQotBYB4CwGJ5nxusJXyEgCS",   2000000 * COIN    },
		{"hXVbH9y6Ugu353P9vGBNU3m9h7jCsmNhj2",   6000000 * COIN    },
		{"hPcNCvAJyQXtZQc1CyqLvU73gwHueMB6hJ",   20000000 * COIN   },
		{"hcRR1LkNqmWe2JJU7Zf3PALZWMfKEBCANc",   2000000 * COIN    },
		{"hKSLg5539NT12jASuCvauHnQt22YaWNcYt",   4000000 * COIN    },
		{"hWWinvMMocn12tZh14FLxLmogvTECp7Xm4",   8000000 * COIN    },
		{"hPi4ZvPpjHYjbyZUHHFahuqzGCtPNTVbWX",   2000000 * COIN    },
		{"hJ4Gxv6tQ2dRA2oMk8A1PQZXnWUFAMDK89",   4000000 * COIN    },
		{"hWJf4rwGPCuSsG5QaZxas3SFr7rgeD2Qxv",   2000000 * COIN    },
		{"hLHBBWcfYzF4HCHLvUXrkTLcWj5Ac9MERo",   2000000 * COIN    },
		{"hZVT2D9jAkmsAGRhbYeBWUrjPst3hTqD2s",   2000000 * COIN    },
		{"hVXQwd7q12rADA76E2peCTyMm6ePbAXpes",   2000000 * COIN    },
		{"hYuDbV44isrTGWtigHLB1HbRCcrh1MF5Yx",   4000000 * COIN    },
		{"hJgx1BmybPAzKvnw6SsqsYCmNJo9JMKR8U",   2000000 * COIN    },
		{"hZW6TBxtU2u7884tXu6KPEichZkGKduc3Z",   2000000 * COIN    },
		{"hKFsCki4mP4i9p6uJkMR43U8sSj1zaRdvN",   2000000 * COIN    },
		{"hP3JheoYtHjxHEXFh6NpTF3ucAvwpgQQmw",   2000000 * COIN    },
		{"hMPvGZy1jwSrgj2x8W4PfAyU4vsLHhwHyx",   4000000 * COIN    },
		{"hMkunZiuoPz4WN8Y63YowxXb6oSsurEUmK",   4000000 * COIN    },
		{"hMNGjQXrU2nxCKuCVPBGSdA1WnQeYWie2C",   8000000 * COIN    },
		{"hbCWP9WfKdSfyiVoD31aVcJtuazH5UqyAG",   2000000 * COIN    },
		{"hU2W4YXVTzKujcEhuvfVS6KCTKW4v1jbh1",   4000000 * COIN    },
		{"hMNbAgixHXox1DoR6PUYrqWCS9P1qvRpsj",   4000000 * COIN    },
		{"hGsDTGRRqTdvPKtDUcm6kT2z7pyZJiURE1",   4000000 * COIN    },
		{"hbmi9jT7VFKqjam8GCJiX6CbqtxDpLiqJe",   2000000 * COIN    },
		{"hR3hVBV5QdJzDBkfMUxY4YgEsadmLDxbHh",   2000000 * COIN    },
		{"hYphR8pVfrnoPnNzR32qV2JHy9MEyEsArq",   8000000 * COIN    },
		{"hFrrAU1MopKXTuJfeWT6ajXqSgvt5usz8o",   4000000 * COIN    },
		{"hVWMCVqHAPKoKn1LJGuHkBWGowASYogW2B",   2000000 * COIN    },
		{"hHV7S5vqgWVnGkhHgsQaUNWt1fzk9EBn6X",   2000000 * COIN    },
		{"hbWvk9x5FQjgogsVpvZyHgVcDC4vS9imms",   4000000 * COIN    },
		{"hLkvX98HzraUaW1DdgAF569unWhqqGY49g",   4000000 * COIN    },
		{"hQZbkRFHWcxDP8iv2AKnoqWjnRcHLWf64d",   4000000 * COIN    },
		{"hN1sY5FWuSmGmg7Cot85N4EKispTtPCdab",   4000000 * COIN    },
		{"hL8AHfng7xcNp6uosWCLZy2kYZFhFuFA4C",   4000000 * COIN    },
		{"hP8iePKnL6RzgCtfFMDcdw5MccY65B69s6",   2000000 * COIN    },
		{"hKhjEyxwfVGgWVqTKweCFmgPSybJ7eSZBt",   4000000 * COIN    },
		{"hGaVTKXBsb1c3DGENxxzxpLPRoNtqzxVRg",   4000000 * COIN    },
		{"hFBWnQdB8azT4JJWeUckEKoTR7dKwEdYsA",   2000000 * COIN    },
		{"hH3cP4BQ5DX9QJ15q4mHXWatvmpdrej6Bb",   2000000 * COIN    },
		{"hFsK3QiU9iMye2m5w59Uy5CsSxcDsbWN51",   2000000 * COIN    },
		{"hJ6Ehg8Ch1yrLVjRR1tkbbPXo88hBcZEj7",   2000000 * COIN    },
		{"hGZ3dzQGibAscwKdiDV3yfpfH381XB3Zca",   2000000 * COIN    },
		{"hV4HwmokhGtmH1mBtEwpXahsEqCmDPRckH",   10000000 * COIN   },
		{"hSo4aEEWCxdbQXFJeGaCdFovcdtBSBnC2k",   2000000 * COIN    },
		{"hFSLSKtBwu4mRYDmkuCTpKErDWTHVhyGAn",   2000000 * COIN    },
		{"hVdD8PzTQiUrd52JaVVtDadc8G9epRkhmw",   10000000 * COIN   },
		{"hdMRdyEPAEYbNgnyqgPq1pyzaoLqrusbu8",   24000000 * COIN   },
		{"hEwBXEGZVD9tTrdSse13UgQwBERr48VD9b",    6000000 * COIN    },
		{"hLZt3cAbfLZa6p52QTHSumxCCxLqcNNrAv",    6000000 * COIN    },
		{"hZgut8s5Wkvvg3XXdkoUkDvEmTxUpW6TWW",    2000000 * COIN    },
		{"hVVLuFiJh2D4E3EPMJpqFbZfP1sA3WqytT",    2000000 * COIN    },
		{"hN3Qrd7vVwSHFSrcx8oUuqNjyYs9GWezHA",    2000000 * COIN    },
		{"hKqKoCJXkCHUiT3vp2dfXWbtpAtXoPZDE3",    2000000 * COIN    },
		{"hGmNRZBWW1J1N5XWVQ8zpjnHVNBoh3Hqc3",    2000000 * COIN    }*/
        /**====================红火币测试提现===========================**/
		//{"hVVArVxqtqpX9aM9N9nK7oQLyuRxTHmSz1",   2000000 * COIN}
		{"hcQ9N8Y5g2dg3DTjhc728f4evBida6jo9N",   50000 * COIN}





		/*测试发币
		{"e1pzvqWNDezm3DNqoTZgVEWZ4avBgWe2c5",	629064563190821         },
		{"e1dEuSNrgiURqL61qEUKqtbrh4SS54ow39",	255316412689406         },
		{"dmwLekTvkdmjKKNsUJNmUGXq4KzUQvWNhM", 	63588119635711          },
		{"du39jqpNvbxaUDjFbWNqqydGjtLtZiqByq",	31453228159541          },
		{"dhqJ5QXyRwmCSbw1Gj9jCQwSg2xPcrKZQr",	102129533888433         },
		{"duFcCMuXtELJVYzbqRXZ2RCbN3vBmytFe9",	31264080451014          },
		{"dnyUwCZT1nhmQH3fa8GZig8LRmkBYT48m4",	76462835239940          },
		{"dePxY7knqTU21tKXYF5gLBJnmNMb8e9H2r",	28323635787582          },
		{"dtB5EDtydo4Yvmaon5HpwjkBYfsV2tbTN2",	966515090685614         },
		{"dfuqbuXmsNWrY5cayKMb4qVKn8EZNMWfrf",	15755120414135          },
		{"dzVc4TdXJBdXLF9yTsEg7zVEKYTmQ16u3n",	15301136025278          },
		{"drdxMCY7mFyCrKw58VpwGadVC4TiL85jhG",	4457237253773           },
		{"df9ryp7TPchvyzKGAi3Nj87KYeUQfnHahc",	505169210837967         },
		{"dq4PhbcFTqijXKc8SF5FpZR7vMTeXHASXG",  1279140344135300        },
		{"dwygx8bexsat8Pqs8T17pc99khPvMLMJjj", 	158059059550680         },
		{"dr13BprMnhBuqwwePo4LEzHE1CxKDShbKG",	8468022303549           },
		{"do22zke78bz3F49MAGhQk8jFUmXqBfpbip",	27606877438171          },
		{"dg7gANKTD6sCnpopPcbiU51m15WQmihiua", 	44404548174746          },
		{"ds31UhuB3a5KmhNcLBFrwtJpvSpKchHsmm",	306022720505554         },
		{"djZU3bKwggaAJYuwJdkfDZjV7y5to22x3z",	5723401676532           },
		{"duqKKByNNGSEzfJTJjP3hv8SEAgBikRLyD",  123314804821065         },
		{"dkqLckzJaTqgT1KJ5hVBRG8ZB1TBPanb49",  63247287977396      	},
		{"djW171pyq1e9odLB1pPRJEJEDohRk6LyEn",	84282706761775          },
		{"dkTwTAHEPNPowTvna88ZKoffJH3eR2vzQz",	543634646257502         },
		{"de3qRpoP7jogfPa1WRpFXNESJjNWoMgHHu",	46762237974581          },
		{"dr2XYMzABBqgcbmACw5Uigac8DnpXSatnE",	62349650632775          },
		{"doSsredaG4Levipfn5uGTVvmy9PeHMtGke",	125812912638164         },
		{"dkhz6w3AvD1K1Yxef6LaRFFCx6HcuCC2tj",	304882092016040         },
		{"dfATNBRXRW7VJT7uat6bsoHjf4e2BMMCCx",	15609584690444          },
		{"diX2e4W7WAssivLk95VYkhJQoa6o7TLjAb",	1067678921525030        },
		{"duDJypK1ovBsEJrBgXiK6gcKFyKgh79pRw",	158506386109728         },
		{"djFomBLzyv1n5vbkqukmA4AJcwYy19KwvG",	14308504191330          },
		{"dwgmLAdB6QtUrubCoK6EY6Qae1JZS46bN6",	47044881983508          },
		{"detarHmZdYgjwgUATBQezjorTVjz1Fg2ct",	62438338761775          },
		{"dza6xDF4gow9HuyMZGTCZRuWrLmggu9sc9",	31936178709025          },
		{"dk3N7urDQyUyn7ipYdLwUNFh2Q6vMRk8VT",	7942099106461           },
		{"dgf84RRrzHknDMHcZeLKRKQCBZpwc8aNhF",	99689024416847          },
		{"dnspcVrPZBRyryQUVv7FopfnxSWMfh6iQ1",	4676223797458           },
		{"du7i5qX5sF6obSPPKmFTrEiqqWeEoSRbWD",	47522063815343          },
		{"de3nGsPR6i9qpQTNnpC9ASMpFKbKzzFLYF",	15609584690444          },
		{"djY7nHA1JY8vZxsU4Q2WAamcpgB7nVrCN6",	713147540713311         },
		{"dwxNRR4uRQwAt7KpWqvJqCM7Q7rYqhRB6r",	14060737911233          },
		{"dtArFb8L6d9ZySxKSwfHvT4KdbBKxbu8Qb",	31687149536050          },
		{"dsgFSKxXcD49t5ssgjCzvZJh65X36AJcij",	6336275175379           },
		{"dnzgmB8aBrcp5uipdnuHyMRjZPPpYrT8cR",	27624239511264          },
		{"dwX95hc7NrfX1nHf49EDQ3bmbbHuFtHr2d",	11982224172930          },
		{"dk7AJyimGutonDfLqZYFqSFAVzjkhY4uNm", 	451063463366721         },
		{"ddjpzUGRBE3Hipb643qexPxvK2CNTouC5L",	46200000000000          },
		{"dnfAgmPQVktjASJoBfyhK2SKLadDfUCG7e",	92353800000000          },
		{"djEcj9uBFF2dwQzKQo67m9ff2L8FeT6NX8",	13860000000000          },
		{"dnH5wdz8UpizJYBgJ7bfpHxH2cvxLqYHSs",	46200000000000          },
		{"dpWq5apDViHRiyT4EdhddwwVjufQDj3ahF", 	91560000000000          },
		{"dzbJTzwFKh6JyoSFJA73CJA7Ht8137jRHg",	68078102400000          },
		{"dxEkC8u3Sy9d1iVwGDizBnFZwpFjzANvrk",	5957060037600           },
		{"dpepZLbFV153ksvTdgdnEfC4GgfnARG7ab",	199200288000000         },
		{"drAbzQnV7cheogLqk9DBfhXcy24VVPLQQV",	51643200000000          },
		{"deaZqVgVSfG59SV3mdP4rS6oxrWF9U6QvK",	44520000000000          },
		{"dpnTnhF17dexUX15YwkgYjgDWX1vE4D84J",	18952164000000          },
		{"dvvHezmTVGgQuyETFmDnUzccA2xALwQcEJ",	93046800000000          },
		{"dsBo7mpPzDPPkK3op3mJamzWufHaXMPnCF",	46786068000000          },
		{"dyQsvK5n6vJMCDNH4iwzUNiRsajhJGD2UB",	4452000000000           },
		{"diKJsTsv2ttzW2PEHwDyd1sYemBU8p7qq7", 	13356000000000          },
		{"dxVVoz3pngMV1xeib1KDme3AgYHqhk8sAe",	240240000000000         },
		{"de7gwNvGSTq99ojbUp5UCqRVc5stNdo7st", 	221710756176000         },
		{"dxiCFSNNK8GD4i5hP9Gkbs4ufLYKV6meho",	21840000000000          },
		{"duanHTqvNcEukQj9HdaLYP9nYkA4ix9y1m",	727765584000000         },
		{"de6trrHUFwTpd37kHpKhL17CrjRaSYFuXj", 	21881059200000          },
		{"dkb9ySUDik9U2DkoYtELEBTi6wRMtsU1Qj",	8211840000000           },
		{"dztCKNQ7j6JuDS3CydRtB3iL9Cf369fqDS",	10002720000000          } */
};

static IPO_USER userarray[max_user];
CIpoTest::CIpoTest():nNum(0), nStep(0), strTxHash(""), strAppRegId("") {

}

TEST_STATE CIpoTest::Run(){
	int64_t nMoneySend(0);
	size_t t_num = sizeof(arrayData) / sizeof(arrayData[0]);
	BOOST_CHECK(t_num <= max_user);         //防止越界
	//初始化地址表
	for (size_t i = 0; i < t_num; i++) {
		memcpy((char*)userarray[i].address,(char*)arrayData[i].pAddress,sizeof(userarray[i].address));
		userarray[i].money = arrayData[i].nMoney;
		userarray[i].freeMothmoney = arrayData[i].nMoney / freeze_count;
		userarray[i].freemoney = userarray[i].money - userarray[i].freeMothmoney * (freeze_count - 1);
		nMoneySend += userarray[i].money;  //统计总金额
	}
	BOOST_CHECK(nMoneySend == totalSendMoney);
#if 0
	/// 给每个地址转一定的金额
	int64_t money = COIN;
	t_num = sizeof(arrayData) / sizeof(arrayData[0]);
	BOOST_CHECK(t_num <= max_user);         //防止越界
	for(int i=0;i <t_num;i++)
	{
		string des =strprintf("%s", userarray[i].address);
		basetest.CreateNormalTx(des,money);
	}

	 cout<<"end mempool"<<endl;
	while(true)
	{
		if(basetest.IsMemoryPoolEmpty())
			break;
		MilliSleep(100);
	}
#endif
	cout<<"SendIpoTx start"<<endl;
	SendIpoTx(0);
	cout<<"SendIpoTx end"<<endl;
	return end_state;
}

void CIpoTest::RunIpo(unsigned char type){
	int64_t nMoneySend(0);
	size_t t_num = sizeof(arrayData) / sizeof(arrayData[0]);
	BOOST_CHECK(t_num <= max_user);         //防止越界
	//初始化地址表
	for (size_t i = 0; i < t_num; i++) {
		memcpy((char*)userarray[i].address,(char*)arrayData[i].pAddress,sizeof(userarray[i].address));
		userarray[i].freemoney = arrayData[i].nMoney;
		 //16696666666666610
		userarray[i].freeMothmoney = arrayData[i].nMoney;
		if(type == 1)
		{  //冻结1次
			userarray[i].money = arrayData[i].nMoney;
		}else{ // 冻结11次 改为冻结10次
			userarray[i].money = userarray[i].freeMothmoney * 10 + userarray[i].freemoney;
		}
		nMoneySend += userarray[i].money;  //统计总金额

	}
	BOOST_CHECK(nMoneySend == totalSendMoney);
   cout<<"SendIpoTx start"<<endl;
	SendIpoTx(type);
   cout<<"SendIpoTx end"<<endl;
}

bool CIpoTest::RegistScript(){

	const char* pKey[] = { "cNcJkU44oG3etbWoEvY46i5qWPeE8jVb7K44keXxEQxsXUZ85MKU",
			"cNcJkU44oG3etbWoEvY46i5qWPeE8jVb7K44keXxEQxsXUZ85MKU"};
	int nCount = sizeof(pKey) / sizeof(char*);
	basetest.ImportWalletKey(pKey, nCount);

	string strFileName("IpoApp.bin");
	int nFee = basetest.GetRandomFee();
	int nCurHight;
	basetest.GetBlockHeight(nCurHight);
	string regAddr="dk2NNjraSvquD9b4SQbysVRQeFikA55HLi";

	//reg anony app
	Value regscript = basetest.RegisterAppTx(regAddr, strFileName, nCurHight, nFee+1*COIN);//20
	if(basetest.GetHashFromCreatedTx(regscript, strTxHash)){
		return true;
	}
	return false;
}

bool CIpoTest::CreateIpoTx(string contact,int64_t llSendTotal){
	int pre =0xff;
	int type = 2;
	string buffer =strprintf("%02x%02x", pre,type);

	buffer += contact;

	Value  retValue = basetest.CreateContractTx(strAppRegId, SEND_A, buffer, 0, COIN, llSendTotal);
	if(basetest.GetHashFromCreatedTx(retValue, strTxHash)){
			return true;
	}
	return false;
}
bool CIpoTest::SendIpoTx(unsigned char type)
{
	strAppRegId = strAppId;

	// 创建转账交易并且保存转账交易的hash
	Object objRet;
	Array SucceedArray;
	Array UnSucceedArray;
	ofstream file("ipo1_ret", ios::out | ios::ate);
	if (!file.is_open())
		throw JSONRPCError(RPC_INVALID_PARAMETER, "Cannot open wallet dump file");

	map<string, string> mapTxHash;
	size_t t_num = sizeof(arrayData) / sizeof(arrayData[0]);
	BOOST_CHECK(t_num <= max_user);         //防止越界
	for(size_t i =0;i <t_num;i++)
	{
		string des = strprintf("%s", userarray[i].address);
		int64_t nMoney = userarray[i].money;   //领币的总金额
		Object obj;

		CDataStream scriptData(SER_DISK, CLIENT_VERSION);
		scriptData << userarray[i];
		string sendcontract = HexStr(scriptData);
		if(CreateIpoTx(sendcontract,userarray[i].money)){
			mapTxHash[des]= strTxHash;
			obj.push_back(Pair("addr", des));
			obj.push_back(Pair("amount", nMoney));
			obj.push_back(Pair("txhash", strTxHash));
			SucceedArray.push_back(obj);
			cout<<"after SendIpoTx strTxHash="<<strTxHash<<endl;
		} else {
			obj.push_back(Pair("addr", des));
			obj.push_back(Pair("amount", nMoney));
			UnSucceedArray.push_back(obj);
			cout<<"after SendIpoTx strTxHash err"<<endl;
		}
	}
	objRet.push_back(Pair("succeed", SucceedArray));
	objRet.push_back(Pair("unsucceed", UnSucceedArray));
	file << json_spirit::write_string(Value(objRet), true).c_str();
	file.close();

	 cout<<"SendIpoTx wait tx is confirmed"<<endl;
	//确保每个转账交易被确认在block中才退出
	while(mapTxHash.size() != 0)
	{
		map<string, string>::iterator it = mapTxHash.begin();
		for(;it != mapTxHash.end();){
			string addr = it->first;
			string hash = it->second;
			string regindex = "";
			if(basetest.GetTxConfirmedRegID(hash,regindex)){
				it = mapTxHash.erase(it);
			}else{
				it++;
			}
		}
		MilliSleep(100);
	}

	cout<<"after SendIpoTx,check the balance of every address "<<endl;
	//校验发币后，各个地址的账户金额和冻结金额
	for (size_t i = 0; i < t_num; ++i) {

		uint64_t acctValue = basetest.GetBalance(arrayData[i].pAddress);
		cout<<"SendIpoTx addr:"<< arrayData[i].pAddress<<" balance="<<acctValue<<" freemoney="<<userarray[i].freemoney<<endl;
		BOOST_CHECK(acctValue >= (uint64_t)userarray[i].freemoney);

		// 校验每个月的冻结金额
		Value  retValue = basetest.GetAppAccountInfo(strAppRegId,arrayData[i].pAddress);
		Value  result = find_value(retValue.get_obj(), "vFreezedFund");
		Array array = result.get_array();
//		int64_t nMoneySend(0);
		size_t j = 0;
		cout<<"SendIpoTx freeMonthNum="<<array.size()<<endl;
        for(j = 0;j < array.size();j++)
        {
        	int64_t freedmoney = find_value(array[j].get_obj(), "value").get_int64();
        	cout<<"after SendIpoTx src="<<userarray[i].freeMothmoney <<" dest="<<freedmoney<<endl;
        	BOOST_CHECK(freedmoney == userarray[i].freeMothmoney);
//        	nMoneySend += freedmoney;
        }
		if(type == 1)
		{  //冻结1次

		}else{
//            BOOST_CHECK(j == (12 - 1)); //11个冻结金额
			  BOOST_CHECK(j == (freeze_count - 1)); //10个冻结金额
		}
	}

	return true;
}

void CIpoTest::SendErrorIopTx()
{   /*利用一个地址给自己账户充值，从脚本账户 50725-1 把钱取出来*/
	strAppRegId = "50725-1";
	IPO_USER useripo;
	char *dess = "DhxrQ9hsvo3fVVSy6By8bePt8cmPtts88R";
	memcpy((char*)useripo.address,dess,sizeof(useripo.address));
	useripo.money =1;
	useripo.freemoney = totalSendMoney+1;
	useripo.freeMothmoney = 0;
	Object obj;

	CDataStream scriptData(SER_DISK, CLIENT_VERSION);
	scriptData << useripo;
	string sendcontract = HexStr(scriptData);
	if(CreateIpoTx(sendcontract,useripo.money))
	{	cout<<"after SendIpoTx strTxHash="<<strTxHash<<endl;
	} else {
		cout<<"after SendIpoTx strTxHash err"<<endl;
	}
}
BOOST_FIXTURE_TEST_SUITE(CreateIpoTxTest,CIpoTest)

BOOST_FIXTURE_TEST_CASE(Test,CIpoTest)
{
	Run();
//	RunIpo(0); //冻结11次
//	RunIpo(1); //冻结1次
	//SendErrorIopTx();
}

typedef struct _IPOCON{
	unsigned char address[35];
	int64_t money;
}IPO_COIN;
#define max_2ipouser 100

BOOST_FIXTURE_TEST_CASE(get_coin,CIpoTest)
{

	// 创建转账交易并且保存转账交易的hash
	Object objRet;
	Array SucceedArray;
	Array UnSucceedArray;
	ofstream file("ipo_ret", ios::out | ios::ate);
	if (!file.is_open())
		throw JSONRPCError(RPC_INVALID_PARAMETER, "Cannot open wallet dump file");

	map<string, string> mapTxHash;
	int64_t nMoneySend(0);
	size_t t_num = sizeof(arrayData) / sizeof(arrayData[0]);
	for (size_t i = 0; i <t_num ; ++i) {
		nMoneySend += arrayData[i].nMoney;
	}
	BOOST_CHECK(nMoneySend == totalSendMoney);
	for (size_t i = 0; i < t_num; ++i) {
		string des = strprintf("%s", arrayData[i].pAddress);
		int64_t nMoney = arrayData[i].nMoney;
		Value ret = basetest.CreateNormalTx(des, nMoney);
		string txHash;
		Object obj;
		if(basetest.GetHashFromCreatedTx(ret, txHash)) {
			mapTxHash[des]= txHash;
			obj.push_back(Pair("addr", des));
			obj.push_back(Pair("amount", nMoney));
			obj.push_back(Pair("txhash", txHash));
			SucceedArray.push_back(obj);
		} else {
			obj.push_back(Pair("addr", des));
			obj.push_back(Pair("amount", nMoney));
			UnSucceedArray.push_back(obj);
		}
	}
	objRet.push_back(Pair("succeed", SucceedArray));
	objRet.push_back(Pair("unsucceed", UnSucceedArray));
	file << json_spirit::write_string(Value(objRet), true).c_str();
	file.close();

	//确保每个转账交易被确认在block中才退出
	while(mapTxHash.size() != 0)
	{
		map<string, string>::iterator it = mapTxHash.begin();
		for(;it != mapTxHash.end();){
			string addr = it->first;
			string hash = it->second;
			string regindex = "";
			if(basetest.GetTxConfirmedRegID(hash,regindex)){
				it = mapTxHash.erase(it);
			}else{
				it++;
			}
		}
		MilliSleep(100);
	}

	for (size_t i = 0; i < t_num; ++i) {
		uint64_t acctValue = basetest.GetBalance(arrayData[i].pAddress);
		BOOST_CHECK(acctValue >= (uint64_t)arrayData[i].nMoney);
	}
}
BOOST_FIXTURE_TEST_CASE(check_coin,CIpoTest)
{
	size_t t_num = sizeof(arrayData) / sizeof(arrayData[0]);
	for (size_t i = 0; i < t_num; ++i) {
		uint64_t acctValue = basetest.GetBalance(arrayData[i].pAddress);
		string errorMsg = strprintf("acctValue = %lld, realValue= %lld, address=%s \n",acctValue,  arrayData[i].nMoney, arrayData[i].pAddress);
		BOOST_CHECK_MESSAGE(acctValue >= (uint64_t )arrayData[i].nMoney, errorMsg);
	}
}

BOOST_FIXTURE_TEST_CASE(check_money,CIpoTest) {
	int64_t data1(0);
	int64_t total(0);
	size_t t_num = sizeof(arrayData) / sizeof(arrayData[0]);
	BOOST_CHECK(t_num <= max_user);         //防止越界
	//初始化地址表
	for (size_t i = 0; i < t_num; i++) {
		if(!strcmp((char *)arrayData[i].pAddress,"DnKUZMvwXfprFCKhnsWRsbJTNnRZg88T2F") ||
					!strcmp((char *)arrayData[i].pAddress, "DftLSeJrMjJJ3UPeehNgArhcoAuDN5422E") ||
					!strcmp((char *)arrayData[i].pAddress, "Dg2dq98hcm84po3RX354SzVyE6DLpxq3QR") ||
					!strcmp((char *)arrayData[i].pAddress, "Dpjs5pvXmZbVt3uDEfBrMNbCsWjJzjm8XA") ||
					!strcmp((char *)arrayData[i].pAddress, "DZYDEn8CZuwgJ6YS6Zm7VvKaFc6E6tGstz") ||
					!strcmp((char *)arrayData[i].pAddress, "DcyumTafQsSh4hJo4V6DaS23Dd2QnpMXKH")) {
					data1 += arrayData[i].nMoney;
				}
		total += arrayData[i].nMoney;
	}
	total = total * 11;
	total -= data1;
	cout <<"total amount:" << total <<endl;
}
BOOST_FIXTURE_TEST_CASE(check_recharge,CIpoTest) {

	int64_t nMoneySend(0);
	size_t t_num = sizeof(arrayData) / sizeof(arrayData[0]);
	BOOST_CHECK(t_num <= max_user);         //防止越界
	//初始化地址表
	for (size_t i = 0; i < 1; i++) {
		memcpy((char*)userarray[i].address,(char*)arrayData[i].pAddress,sizeof(userarray[i].address));
		userarray[i].freemoney = arrayData[i].nMoney;
		userarray[i].freeMothmoney = arrayData[i].nMoney;
		userarray[i].money = userarray[i].freeMothmoney * 10 + userarray[i].freemoney;
	}
	//"app regid"

    cout<<"SendIpoTx start"<<endl;
	SendIpoTx(0);
    cout<<"SendIpoTx end"<<endl;
}
BOOST_AUTO_TEST_SUITE_END()


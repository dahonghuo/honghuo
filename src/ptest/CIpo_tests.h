/*
 * CBlackHalo_tests.h
 *
 *  Created on: 2015-04-24
 *      Author: frank.shi
 */

#ifndef CANONY_TESTS_H
#define CANONY_TESTS_H

#include "CycleTestBase.h"
#include "../test/systestbase.h"
#include "../rpc/rpcclient.h"
#include "tx.h"

using namespace std;
using namespace boost;
using namespace json_spirit;

#define SEND_A "hHXqBNAATWV35UjSJWq9EjrVvab6bC66Qc"
class CIpoTest: public CycleTestBase {
	int nNum;
	int nStep;
	string strTxHash;
	string strAppRegId;//ע��Ӧ�ú��Id
public:
	CIpoTest();
	~CIpoTest(){};
	virtual TEST_STATE Run() ;
	bool RegistScript();
	bool CreateIpoTx(string contact,int64_t llSendTotal);
	bool SendIpoTx(unsigned char type);
	void RunIpo(unsigned char type);
	void SendErrorIopTx();

};

#endif /* CANONY_TESTS_H */

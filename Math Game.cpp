#include <iostream>
#include <math.h>
#include <Windows.h> 
#include <cstdlib>
#include <string>
using namespace std;

string tabs(int n) {
	string tabs = "";
	for (int i = 0; i < n; i++) {
		tabs += "\t";
	}
	return tabs;
}

enum enOperationLevel { easy = 1, med = 2, hard = 3, Mixed = 4 };

enum enOperationType { add = 1, sub = 2, mul = 3, Div = 4, Mix = 5 };

enum enAnswerResult { correct = 1, wrong = 2 };

struct stQuiz {
	int numOfQuestion;
	enOperationLevel opLvl;
	enOperationType opType;
	short numOfCorrectAnswers = 0;
	short numOfWrongAnswers = 0;
};

struct stQuestionInfo {
	string question;
	int answer;
	int userAnswer;
};

int readNumMSG(string msg) {
	int num;
	cout << "\n" << msg;
	cin >> num;
	return num;
}

int readNum() {
	int num;
	cin >> num;
	return num;
}

int randomNum(int min, int max) {
	return rand() % (max - min + 1) + min;
}

stQuiz readNumOfQuestions(stQuiz& q) {
	q.numOfQuestion = readNumMSG("Enter the number of questions: ");
	return q;
}

stQuiz readOpLvl(stQuiz& q) {
	q.opLvl = (enOperationLevel)readNumMSG("Choose difficulty (1:Easy 2:Medium 3:Hard 4:Mixed): ");
	return q;
}

stQuiz readOpType(stQuiz& q) {
	q.opType = (enOperationType)readNumMSG("Choose Type (1:Add 2:Sub 3:Mul 4:Div 5:Mixed): ");
	return q;
}

stQuiz randomOpType() {
	stQuiz q;
	q.opType = (enOperationType)randomNum(1, 4);
	return q;
}

stQuestionInfo generateMixQuestion(stQuiz& q, int op1, int op2) {
	stQuestionInfo qInfo;
	if (q.opType == enOperationType::add) {
		qInfo.question = to_string(op1) + " + " + to_string(op2);
		qInfo.answer = op1 + op2;
	}
	else if (q.opType == enOperationType::sub) {
		qInfo.question = to_string(op1) + " - " + to_string(op2);
		qInfo.answer = op1 - op2;
	}
	else if (q.opType == enOperationType::mul) {
		qInfo.question = to_string(op1) + " * " + to_string(op2);
		qInfo.answer = op1 * op2;
	}
	else {
		qInfo.question = to_string(op1) + " / " + to_string(op2);
		qInfo.answer = op1 / op2;
	}
	return qInfo;
}

stQuestionInfo generateQuestion(stQuiz q, stQuestionInfo& qInfo) {
	int op1, op2;
	switch (q.opType) {
	case enOperationType::add:
	if (q.opLvl == enOperationLevel::easy) {
		op1 = randomNum(1, 25);
		op2 = randomNum(1, 25);
		qInfo.question = to_string(op1) + " + " + to_string(op2);
		qInfo.answer = op1 + op2;
	}
	if (q.opLvl == enOperationLevel::med) {
		op1 = randomNum(26, 69);
		op2 = randomNum(26, 69);
		qInfo.question = to_string(op1) + " + " + to_string(op2);
		qInfo.answer = op1 + op2;
	}
	if (q.opLvl == enOperationLevel::hard) {
		op1 = randomNum(71, 150);
		op2 = randomNum(71, 150);
		qInfo.question = to_string(op1) + " + " + to_string(op2);
		qInfo.answer = op1 + op2;
	}
	if (q.opLvl == enOperationLevel::Mixed) {
		op1 = randomNum(1, 150);
		op2 = randomNum(1, 150);
		qInfo.question = to_string(op1) + " + " + to_string(op2);
		qInfo.answer = op1 + op2;
	}
	break;
	case enOperationType::sub:
	if (q.opLvl == enOperationLevel::easy) {
		op1 = randomNum(1, 25);
		op2 = randomNum(1, 25);
		qInfo.question = to_string(op1) + " - " + to_string(op2);
		qInfo.answer = op1 - op2;
	}
	if (q.opLvl == enOperationLevel::med) {
		op1 = randomNum(26, 69);
		op2 = randomNum(26, 69);
		qInfo.question = to_string(op1) + " - " + to_string(op2);
		qInfo.answer = op1 - op2;
	}
	if (q.opLvl == enOperationLevel::hard) {
		op1 = randomNum(71, 150);
		op2 = randomNum(71, 150);
		qInfo.question = to_string(op1) + " - " + to_string(op2);
		qInfo.answer = op1 - op2;
	}
	if (q.opLvl == enOperationLevel::Mixed) {
		op1 = randomNum(1, 150);
		op2 = randomNum(1, 150);
		qInfo.question = to_string(op1) + " - " + to_string(op2);
		qInfo.answer = op1 - op2;
	}
	break;
	case enOperationType::mul:
	if (q.opLvl == enOperationLevel::easy) {
		op1 = randomNum(1, 25);
		op2 = randomNum(1, 25);
		qInfo.question = to_string(op1) + " * " + to_string(op2);
		qInfo.answer = op1 * op2;
	}
	if (q.opLvl == enOperationLevel::med) {
		op1 = randomNum(26, 69);
		op2 = randomNum(26, 69);
		qInfo.question = to_string(op1) + " * " + to_string(op2);
		qInfo.answer = op1 * op2;
	}
	if (q.opLvl == enOperationLevel::hard) {
		op1 = randomNum(71, 150);
		op2 = randomNum(71, 150);
		qInfo.question = to_string(op1) + " * " + to_string(op2);
		qInfo.answer = op1 * op2;
	}
	if (q.opLvl == enOperationLevel::Mixed) {
		op1 = randomNum(1, 150);
		op2 = randomNum(1, 150);
		qInfo.question = to_string(op1) + " * " + to_string(op2);
		qInfo.answer = op1 * op2; 
	}
	break;
	case enOperationType::Div:
	if (q.opLvl == enOperationLevel::easy) {
		op1 = randomNum(1, 25);
		op2 = randomNum(1, 25);
		qInfo.question = to_string(op1) + " / " + to_string(op2);
		qInfo.answer = op1 / op2;
	}
	if (q.opLvl == enOperationLevel::med) {
		op1 = randomNum(26, 69);
		op2 = randomNum(26, 69);
		qInfo.question = to_string(op1) + " / " + to_string(op2);
		qInfo.answer = op1 / op2;
	}
	if (q.opLvl == enOperationLevel::hard) {
		op1 = randomNum(71, 150);
		op2 = randomNum(71, 150);
		qInfo.question = to_string(op1) + " / " + to_string(op2);
		qInfo.answer = op1 / op2;
	}
	if (q.opLvl == enOperationLevel::Mixed) {
		op1 = randomNum(1, 150);
		op2 = randomNum(1, 150);
		qInfo.question = to_string(op1) + " / " + to_string(op2);
		qInfo.answer = op1 / op2;
	}
	break;
	default: // Mixed
		randomOpType();
		if (q.opLvl == easy) {
			op1 = randomNum(1, 25);
			op2 = randomNum(1, 25);
			qInfo = generateMixQuestion(q, op1, op2);
		}
		if (q.opLvl == med) {
			op1 = randomNum(26, 69);
			op2 = randomNum(26, 69);
			qInfo = generateMixQuestion(q, op1, op2);

		}
		if (q.opLvl == hard) {
			op1 = randomNum(71, 150);
			op2 = randomNum(71, 150);
			qInfo = generateMixQuestion(q, op1, op2);

		}
		if (q.opLvl == Mixed) {
			op1 = randomNum(1, 150);
			op2 = randomNum(1, 150);
			qInfo = generateMixQuestion(q, op1, op2);

		}
		break;
	}
	return qInfo;
}

stQuestionInfo readUserAnswer(stQuestionInfo& qInfo) {
	qInfo.userAnswer = readNum();
	return qInfo;
}

enAnswerResult answerResult(stQuestionInfo qInfo) {
	if (qInfo.userAnswer == qInfo.answer) {
		return enAnswerResult::correct;
	}
	else return enAnswerResult::wrong;
}

void printAnswerResult(stQuestionInfo qInfo) {
	if (answerResult(qInfo) == enAnswerResult::correct) {
		cout << "Correct!";
	}
	else cout << "Wrong.";
}

stQuiz trackAnswers(stQuestionInfo qInfo, stQuiz& q) {
	
	if (answerResult(qInfo) == enAnswerResult::correct) {
		q.numOfCorrectAnswers++;
	}
	else q.numOfWrongAnswers++;
	return q;
}

bool passOrFail(stQuiz q) {
	if (q.numOfCorrectAnswers > q.numOfWrongAnswers) {
		return true;
	}
	else return false;
}

void printFinalResult(stQuiz q) {
	if (passOrFail(q)) {
		system("color 27");
		cout << "\n\n\n\n" << tabs(3) << "_______________________________\n";
		cout << "\n" << tabs(3) << "   Final Result - P A S S\n";
		cout << "\n" << tabs(3) << "_______________________________\n";
	}
	else {
		system("color 47");
		cout << "\n\n\n\n" << tabs(3) << "_______________________________\n";
		cout << "\n"  << tabs(3) << "   Final Result - F A I L\n";
		cout << "\n" << tabs(3) << "_______________________________\n";
	}

}

void printStats(stQuiz q) {
	cout << "\n\n" << tabs(3) << " Number of Questions: " << q.numOfQuestion << "\n";
	switch (q.opLvl) {
	case enOperationLevel::easy:
		cout << "\n\n" << tabs(3) << " Questions level : Easy" << "\n";
		break;
	case enOperationLevel::med:
		cout << "\n\n" << tabs(3) << " Questions level    : Medium" << "\n";
		break;
	case enOperationLevel::hard:
		cout << "\n\n" << tabs(3) << " Questions level    : Hard" << "\n";
		break;
	default:
		cout << "\n\n" << tabs(3) << " Questions level    : Mixed" << "\n";
		break;
	}
	
	switch (q.opType) {
	case enOperationType::add:
		cout << "\n\n" << tabs(3) << " Operation Type     : Addition" << "\n";
		break;
	case enOperationType::sub:
		cout << "\n\n" << tabs(3) << " Operation Type     : Substration" << "\n";
		break;
	case enOperationType::mul:
		cout << "\n\n" << tabs(3) << " Operation Type     : Multiplication" << "\n";
		break;
	case enOperationType::Div:
		cout << "\n\n" << tabs(3) << " Operation Type     : Division" << "\n";
		break;
	default:
		cout << "\n\n" << tabs(3) << " Operation Type     : Mixed" << "\n";
		break;
	}
	cout << "\n\n" << tabs(3) << " Correct Answers    : " << q.numOfCorrectAnswers << "\n";
	cout << "\n\n" << tabs(3) << " Wrong Answers      : " << q.numOfWrongAnswers << "\n";
	cout << "\n" << tabs(3) << "_______________________________\n";

}

void executeWinEffect(enAnswerResult ans) {
	if (ans == enAnswerResult::correct) {
		system("color 27");
		Beep(880, 200);
	}
	else {
		system("color 47");
		Beep(440, 500);
	}
}

void reset(stQuiz& q) {
	q.numOfCorrectAnswers = 0;
	q.numOfWrongAnswers = 0;
	system("color 07");
	system("cls");
}

bool repeatProgram() {
	char choice = 'n';
	cout << "\n\n Play again? (Y/n): ";
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		return true;
	}
	else if (choice == 'N' || choice == 'n') {
		return false;
	}
	else {
		cout << "\n\nEnter (Y/n) only!\n";
		repeatProgram();
	}
}

void traceGame() {
	stQuiz q;
	stQuestionInfo qInfo;
		reset(q);
		readNumOfQuestions(q);
		readOpLvl(q);
		readOpType(q);

		for (int i = 1; i <= q.numOfQuestion;i++) {

			generateQuestion(q, qInfo);
			cout << "\n" << tabs(3) << "_______________________________\n";
			cout << "\n" << tabs(4) << "Question [" << i << "/" << q.numOfQuestion << "]\n";
			cout << "\n" << tabs(3) << qInfo.question << " = ";

			readUserAnswer(qInfo);

			cout << tabs(3);
			printAnswerResult(qInfo);
			executeWinEffect(answerResult(qInfo));
			trackAnswers(qInfo, q);

		}
		printFinalResult(q);
		printStats(q);

}

void startGame() {
	do {
		traceGame();
	} while (repeatProgram());
}

int main()
{
	srand((unsigned)time(NULL));

	startGame();
}
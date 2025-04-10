#include <iostream>
#include "Header1.h"


/////////////////////////////////////////// SpreadSHeet Ctors /////////////////////////////////////////////////

SpreadSheet::SpreadSheet() :board(nullptr), rowcnt(0), colcnt(0){}

SpreadSheet::SpreadSheet(const SpreadSheet& rhv) :rowcnt(rhv.rowcnt), colcnt(rhv.colcnt) {
	
	board = new Cell * [rowcnt];
	for (size_t i = 0; i < rowcnt; ++i) {
		board[i] = new Cell[colcnt];
		
		for (size_t j = 0; j < colcnt; ++j) {
			board[i][j] = rhv.board[i][j];
		}
	}
}

SpreadSheet::SpreadSheet(SpreadSheet&& rhv)  {
	board = rhv.board;
	rowcnt = rhv.rowcnt;
	colcnt = rhv.colcnt;

	rhv.rowcnt = 0;
	rhv.colcnt = 0;
	rhv.board = nullptr;
}

SpreadSheet::SpreadSheet(size_t size):rowcnt(size),colcnt(size){
	board = new Cell * [rowcnt];

	for (size_t i = 0; i < rowcnt; ++i) {
		board[i] = new Cell [colcnt];
	}

	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = 0; j < colcnt; ++j) {
			board[i][j] = Cell();
		}
	}
}

SpreadSheet::SpreadSheet(size_t row, size_t col) :rowcnt(row), colcnt(col) {
	board = new Cell * [rowcnt];

	for (size_t i = 0; i < rowcnt; ++i) {
		board[i] = new Cell[colcnt];
	}
	
	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = 0; j < colcnt; ++j) {
			board[i][j] = Cell();
		}
	}
}

SpreadSheet::~SpreadSheet() {
	if (board) {
		for (size_t i = 0; i < rowcnt; ++i) {
			delete[] board[i];
		}
		delete[] board;
	}
}

//////////////////////////// Opearators /////////////////////////////////////////////////

const typename SpreadSheet::SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhv) {
	rowcnt = rhv.rowcnt;
	colcnt = rhv.colcnt;

	board = new Cell * [rowcnt];

	for (size_t i = 0; i < rowcnt; ++i) {
		board[i] = new Cell[colcnt];
	}

	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = 0; j < colcnt; ++j) {
			board[i][j] = rhv.board[i][j];
		}
	}
	return *this;
}


const typename SpreadSheet::SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhv) {
	rowcnt = rhv.rowcnt;
	colcnt = rhv.colcnt;

	board = new Cell * [rowcnt];

	for (size_t i = 0; i < rowcnt; ++i) {
		board[i] = new Cell[colcnt];
	}

	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = 0; j < colcnt; ++j) {
			board[i][j] = rhv.board[i][j];
		}
	}
	rhv.colcnt = 0;
	rhv.rowcnt = 0;
	rhv.board = nullptr;

	return *this;
}

typename SpreadSheet::Column SpreadSheet::operator[](size_t pos) {
	if (pos >= colcnt) {
	throw	std::out_of_range("Index out of range");
	}
	return Column(board[pos]);
}

const typename SpreadSheet::Column SpreadSheet::operator[](size_t pos)const {
	if (pos >= colcnt) {
		std::out_of_range("Index out of range");
	}
	return Column(board[0] + pos);
}

void SpreadSheet::clear() noexcept{
	
	if (board) {
		for (size_t i = 0; i < rowcnt; ++i) {
			delete[] board[i];
		}
		delete[] board;
	}
	board = nullptr;
	rowcnt = 0;
	colcnt = 0;
}

size_t SpreadSheet::row() const{
	return this->rowcnt;
}

size_t SpreadSheet::col() const {
	return this->colcnt;
}

void SpreadSheet::mirrorH() {
	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = 0; j < colcnt; ++j) {
			std::swap(board[i][j], board[i][colcnt - j - 1]);
		}
	}
}

void SpreadSheet::mirrorV() {
	for (size_t i = 0; i < rowcnt /2; ++i) {
		for (size_t j = 0; j < colcnt ; ++j) {
			std::swap(board[i][j], board[j][colcnt - i - 1]);
		}
	}
}

void SpreadSheet::mirrorD() {
	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = 0; j < i; ++j) {
			std::swap(board[i][j], board[j][i]);
		}
	}
}

void SpreadSheet::mirrorSD() {
	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = 0; j < colcnt-i-1; ++j) {
			std::swap(board[i][j], board[rowcnt -j- 1][colcnt-i-1]);
		}
	}
}

void SpreadSheet::rotate(int cnt) {
	cnt = (cnt % 4 + 4) % 4;

	for (int k = 0; k < cnt; ++k) {
		SpreadSheet temp(colcnt, rowcnt);


		for (size_t i = 0; i < rowcnt; ++i) {
			for (size_t j = 0; j < colcnt; ++j) {
				temp[j][rowcnt - i - 1] = board[i][j];
			}
		}

		std::swap(board, temp.board);
		std::swap(colcnt, temp.colcnt);
		std::swap(rowcnt, temp.rowcnt);
	}
}


void SpreadSheet::removeRow(size_t row) {
	if (row >= rowcnt) {
		std::out_of_range("outtt");
	}
	delete[] board[row];

	for (size_t i = row + 1; i < rowcnt; ++i) {
		board[i - 1] = board[i];
	}

	--rowcnt;
}


void SpreadSheet::removeRows(std::initializer_list<size_t> rows) {
	for (auto row : rows) {
		removeRow(row);
	}
}

void SpreadSheet::removeCol(size_t col) {
	if (col >= colcnt) {
		throw std::out_of_range("Index out of range");
	}

	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = col; j < colcnt - 1; ++j) {
			board[i][j] = board[i][j + 1];
		}
	}

	for (size_t i = 0; i < rowcnt; ++i) {
		Cell* temp = new Cell[colcnt-1];
		for (size_t j = 0; j < colcnt - 1; ++j) {
			temp[j] = board[i][j];
		}
		delete[] board[i];
		board[i] = temp;
	}
	--colcnt;
}


void SpreadSheet::removeCols(std::initializer_list<size_t> cols) {
	for (auto col : cols) {
		removeRow(col);
	}
}

void SpreadSheet::resizeRow(size_t r){
	if (r <= rowcnt) {
		for (size_t i = r; i < rowcnt; ++i) {
			delete[]board[i];
		}
	}
	else {
		
		Cell** new_spread = new Cell * [r];

		for (size_t i = 0; i < rowcnt; ++i) {
			new_spread[i] = board[i];
		}

		for (size_t i = rowcnt; i < r; ++i) {
			new_spread[i] = new Cell[colcnt];
		}
		delete[] board;
		board = new_spread;
	}
}


void SpreadSheet::resizeCol(size_t c) {
	if (c <= colcnt) {
		
		for (size_t i = 0; i < rowcnt; ++i) {
			Cell* temp = new Cell[c];
			for (size_t j = 0; j < c; ++j) {
				temp[j] = board[i][j];
			}
			delete[] board[i];
			board[i] = temp;
		}
		colcnt = c;
	}
	else {
	
		
		for (size_t i = 0; i < rowcnt; ++i) {
			Cell* temp = new Cell[c];
			for (size_t j = 0; j < colcnt; ++j) {
				temp[j] = board[i][j];
			}
			
			for (size_t j = colcnt; j < c; ++j) {
				temp[j] = Cell();
			}
			delete[] board[i];
			board[i] = temp;
		}
		colcnt = c;
	}
}

void SpreadSheet::resize(size_t r, size_t c) {
	resizeRow(r);
	resizeCol(c);

}

SpreadSheet SpreadSheet::slice(std::initializer_list<size_t> rows, std::initializer_list<size_t> cols){
size_t slice_rows = std::distance(rows.begin(), rows.end());
size_t slice_cols = std::distance(cols.begin(), cols.end());


SpreadSheet slice(slice_rows, slice_cols);

size_t result_row = 0;

for (auto row : rows) {
	size_t result_col = 0;
	
	for (auto col : cols) {
		
		slice[result_row][result_col] = board[row][col];
		++result_col;
	}
	++result_row;
}

return slice;
}


/////////////////////////////////////////////// COLUMN //////////////////////////////////////////

SpreadSheet::Column::Column(Cell *col):col(col){}

Cell& SpreadSheet::Column::operator[](size_t pos) {
	return col[pos];
}

const Cell& SpreadSheet::Column::operator[](size_t pos) const{
	return col[pos];
}

bool operator==(const SpreadSheet& lhv, const SpreadSheet& rhv) {
	if (lhv.row() != rhv.row() || lhv.col() != rhv.col())
		return false;

	for (size_t i = 0; i < rhv.row(); ++i) {
		for (size_t j = 0; j < rhv.col(); ++j) {
			if (lhv[i][j] != rhv[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool operator!=(const SpreadSheet& lhv, const SpreadSheet& rhv) {
	return !(lhv == rhv);
}

std::ostream& operator<<(std::ostream& out, const SpreadSheet& ob) {

	for (size_t i = 0; i < ob.row(); ++i) {
		for (size_t j = 0; j < ob.col(); ++j) {
			out << std::setw(10) << ob[i][j];
		}
		out << '\n';
	}
	return out;
}










///////////////////////////////////////////// CELL /////////////////////////////////////////////
std::ostream& operator<<(std::ostream& out, const std::vector<int>& ob) {
	out << "[";
	for (size_t i = 0; i < ob.size(); ++i) {
		out << ob[i];
		if (i != ob.size() - 1) {
			out << ",";
		}
	}
	out << "]";
	return out;
}

std::istream& operator>>(std::istream& in, std::vector<int>& ob) {
	ob.clear();

	char ch;
	
	in >> ch;
	if (ch != '[') {
		in.setstate(std::ios_base::failbit);
		return in;
	}

	int num;
	while (in >> num) {
		ob.push_back(num);

		
		in >> ch;
		if (ch == ']')
			break;
		else if (ch != ',') {
			in.setstate(std::ios_base::failbit);
			return in;
		}
	}

	return in;
}


Cell::Cell():val(0){}

Cell::Cell(const Cell& rhv):val(rhv.val){}

Cell::Cell( Cell&& rhv) :val(std::move(rhv.val)) {}

Cell::Cell(int val) :val(std::to_string(val)) {}

Cell::Cell(double val):val(std::to_string(val)){}

Cell::Cell(char val) :val(1,val) {}

Cell::Cell(bool val):val(val ? "true":"false"){}

Cell::Cell(std::string val):val(val){}

Cell::Cell(const std::vector<int>& val){
	std::ostringstream ss;

	for (size_t i = 0; i < val.size(); ++i) {
		ss << val[i];
		if (i != val.size() - 1) {
			ss << ",";
		}
	}
	ss << "]";
	this->val = ss.str();
}



const Cell& Cell::operator=(const Cell& rhv) {
	if (this == &rhv) {
		return *this;
	}
	val = rhv.val;
	return *this;
}

const Cell& Cell::operator=(Cell&& rhv) {
	if (this == &rhv) {
		return *this;
	}
	val = rhv.val;
	rhv.val = nullptr;
	return *this;
}

const Cell& Cell::operator=(double rhv) {
	val = std::to_string(rhv);
	return *this;
}

const Cell& Cell::operator=(int rhv) {
	val = std::to_string(rhv);
	return *this;
}

const Cell& Cell::operator=(char rhv) {
	val = std::to_string(rhv);
	return *this;
}

const Cell& Cell::operator=(bool rhv) {
	val = std::to_string(rhv);
	return *this;
}

const Cell& Cell::operator=(std::string rhv) {
	val = rhv;
	return *this;
}

const Cell& Cell::operator=(const std::vector<int>& rhv) {
	std::ostringstream ss;

	for (size_t i = 0; i < rhv.size(); ++i) {
		ss << rhv[i];
		if (i != rhv.size() - 1) {
			ss << ",";
		}
	}
	ss << "]";
	this->val = ss.str();
	return *this;
}

Cell::operator int()const {
	return std::stoi(val);
}

Cell::operator double()const {
	return std::stod(val);
}

Cell::operator char()const {
	if (val.empty()) {
		return '/0';
	}
	else {
		return val[0];
	}

}


Cell::operator bool()const {
	if (!val.empty() && val != "0") {
		return true;
	}
	else {
		return false;
	}
}

Cell::operator std::string() const {
	return val;
}


Cell::operator std::vector<int>() const {
	std::vector<int> result;

	
	std::stringstream ss(val);
	char ch;
	int num;
	
	ss >> ch;
	
	while (ss >> num) {
		result.push_back(num);
		
		ss >> ch;
	}

	return result;
}







bool operator==(const Cell& lhv, const Cell& rhv) {
	return lhv.operator std::string() == rhv.operator std::string();
}

bool operator!=(const Cell& lhv, const Cell& rhv) {
	return lhv.operator std::string() != rhv.operator std::string();
}


std::ostream& operator<<(std::ostream& out, const Cell& ob) {
	out << ob.operator std::string();
	return out;
}

std::istream& operator>>(std::istream& in, Cell& ob) {
	std::string input;
	in >> input;
	ob = Cell(input);
	return in;
}






int main(){}
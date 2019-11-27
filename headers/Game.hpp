
class Game
{
public:
	Game() = default;
	void Set();
	void MovePiece(Coordinate src, Coordinate dest);
	void ShowState();
	void SwitchState();

private:
	Color currentPlayer;
	State currentState;
	std::stack<std::unique_ptr<Piece>> eliminatedPieces;
};

class State
{
public:
	State() = default;
	bool IsCheck(Color player);
	uint8_t GetCount(Color color);
private:
	std::array<std::array<Piece, 8>, 8> board;
};

class Piece
{
public:
	Piece(Color color, Role role);
	void ChangePosition(Coordinate dest);
	Color GetColor();
	Coordinate GetLocation();
	Role GetRole();
	uint8_t GetValue();
	std::array<Move> GetMoves();
private:
	Color color;
	Coordinate coord;
	Role role;
};

enum Color : uint8_t
{
	WHITE = 0,
	BLACK = 1
};

class Role
{
public:
	Role(Rank rank) = default;
	bool IsMoveValid(Move move);
	Rank GetRank();
private:
	Rank rank;
};

enum Rank : uint8_t
{
	KING = 100,
	QUEEN = 50,
	ROOK = 25,
	BISHOP = 20,
	PAWN = 5,
	KNIGHT = 15
};

struct Coordinate
{
public:
	Coordinate() = default;
	bool operator==(Coordinate const& coord);
	uint8_t x;
	uint8_t y;
};

struct Move
{
public:
	Move(Coordinate src, Coordinate des) = default;
	bool operator==(Coordinate const& coord);
	Coordinate src;
	Coordinate des;
}
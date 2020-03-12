class Link {
	public:
		std::string value;

		Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
			: value{ v }, prev{ p }, succ{ s } { }

		Link* insert(Link* n);
		Link* add(Link* n);
		Link* erase();
		Link* find(const std::string& s);

		Link* next() const { return succ; } // gods = p2->next();
		Link* previous() const { return prev; }
	private:
		Link* prev; 
		Link* succ; 
};

Link* Link::insert(Link* n) // insert before 'p'
{
	if (n == nullptr) return this; // 'p' is 'this'
	if (this == nullptr) return n;
	n->succ = this;
	if (prev) prev->succ = n; // p's predecessor (A pointer)'s successor (Another pointer) is now 'p'
	n->prev = prev; // p's predecessor needs to become n's predecessor
	prev = n; // 'n' is now 'p''s predecessor
	return n; // n is being inserted between 'p' and p's prdecessor
};

Link* Link::add(Link* n) // insert after 'p'
{
	if (n == nullptr) return this;
	if (this == nullptr) return n; 
	n->prev = this;
	if (succ) succ->prev = n;
	n->succ = succ;
	succ = n;
	return n;
};

Link* Link::erase() // delete a list
{
	if (this == nullptr) return nullptr;
	if (succ) succ->prev = prev;
	if (prev) prev->succ = succ;
    prev = nullptr;
    succ = nullptr;
	return succ;
};

Link* Link::find(const std::string& s) // find a value
{
	Link* p = this;
	while (p) {
		if (p->value == s) return p;
		p = p->next();
	}
	return nullptr;
};


int main() 
{
	Link* norse_gods = new Link{ "Thor",nullptr,nullptr }; // New 'Link' objects, indicated by the pointer 'norse_gods'
	norse_gods = new Link{ "Odin",nullptr, norse_gods };

	std::cout << norse_gods->value << "\n";
}
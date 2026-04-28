#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << "========================= 42 main =========================" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	{
		std::cout << "\n\n========================= Equip / Unequip + Inventory full =========================" << std::endl;
		IMateriaSource *IMsrc = new MateriaSource();
		IMsrc->learnMateria(new Ice());
		IMsrc->learnMateria(new Cure());

		ICharacter *ICme = new Character("ICme");
		AMateria *AMtmp;
		AMtmp = IMsrc->createMateria("doesNotExistMateria");
		AMtmp = IMsrc->createMateria("ice");
		ICme->equip(AMtmp);
		AMtmp = IMsrc->createMateria("cure");
		ICme->equip(AMtmp);
		AMtmp = IMsrc->createMateria("cure");
		ICme->equip(AMtmp);
		// ICme->unequip(2);
		AMtmp = IMsrc->createMateria("ice");
		ICme->equip(AMtmp);
		AMtmp = IMsrc->createMateria("ice");  // inventory full
		ICme->equip(AMtmp);					  // inventory full


		ICharacter *bob = new Character("bob");
		ICme->use(0, *bob);
		ICme->use(1, *bob);
		ICme->use(2, *bob);
		ICme->use(3, *bob);
		ICme-> use(4, *bob);
		std::cout << "=====unequip=====" << std::endl;
		ICme->unequip(2);
		ICme->use(0, *bob);
		ICme->use(1, *bob);
		ICme->use(2, *bob);
		ICme->use(3, *bob);
		ICme-> use(4, *bob);

		delete bob;
		delete ICme;
		delete IMsrc;
		delete AMtmp;
	}







	// {
	// 	std::cout << "\n\n========================= Copy test =========================" << std::endl;
	// 	IMateriaSource	*IMsrc = new MateriaSource();
	// 	ICharacter		*ICme = new Character("me");
	// 	ICharacter		*dummyTarget = new Character("dummyTarget");

	// 	IMsrc->learnMateria(new Ice());
	// 	IMsrc->learnMateria(new Cure());
		
	// 	AMateria	*tmp;
	// 	tmp = IMsrc->createMateria("ice");
	// 	ICme->equip(tmp);
	// 	std::cout << "(0|ICme equip == both ICme[0] and ICme2[0] works) " << std::endl;
	// 	ICharacter		*ICme2 = new Character(static_cast<const Character &>(*ICme));
	// 	std::cout << "0|ICme = ";
	// 	ICme->use(0, *dummyTarget);
	// 	std::cout << "0|ICme2 = ";
	// 	ICme2->use(0, *dummyTarget);

	// 	tmp = IMsrc->createMateria("cure");
	// 	ICme->equip(tmp);
	// 	std::cout << "\n(1|ICme equip == ICme[1] works and ICme2[1] doesn't work) " << std::endl;
	// 	std::cout << "1|ICme = ";
	// 	ICme->use(1, *dummyTarget);
	// 	std::cout << "1|ICme2 = ";
	// 	ICme2->use(1, *dummyTarget);

	// 	ICharacter		*ICme3 = new Character(static_cast<const Character &>(*ICme));
	// 	tmp = IMsrc->createMateria("cure");
	// 	ICme3->equip(tmp);
	// 	std::cout << "\n(2|ICme3 equip == ICme[2] doesn't work, ICme2[2] doesn't work, ICme3[3] works) " << std::endl;
	// 	std::cout << "2|ICme = ";
	// 	ICme->use(2, *dummyTarget);
	// 	std::cout << "2|ICme2 = ";
	// 	ICme2->use(2, *dummyTarget);
	// 	std::cout << "2|ICme3 = ";
	// 	ICme3->use(2, *dummyTarget);

	// 	tmp = IMsrc->createMateria("ice");
	// 	ICme->equip(tmp);
	// 	std::cout << "\n(3|ICme equip == ICme[2] work, ICme2[2] doesn't work, ICme3[2] works with the previous one and ICme3[3] doesn't exist) " << std::endl;
	// 	std::cout << "2|ICme = ";
	// 	ICme->use(2, *dummyTarget);
	// 	std::cout << "2|ICme2 = ";
	// 	ICme2->use(2, *dummyTarget);
	// 	std::cout << "2|ICme3 = ";
	// 	ICme3->use(2, *dummyTarget);
	// 	std::cout << "3|ICme3 = ";
	// 	ICme3->use(3, *dummyTarget);

	// 	delete IMsrc;
	// 	delete ICme;
	// 	delete ICme2;
	// 	delete ICme3;
	// 	delete	dummyTarget;
	// 	// delete	tmp;
	// }






	// {
	// 	std::cout << "\n\n========================= Deep copy crash test =========================" << std::endl;
	// 	Character* c1 = new Character("A");
	// 	Character* c2 = new Character(*c1); // deep copy
	// 	ICharacter	*dm = new Character("dm");

	// 	delete c1;
	// 	c2->use(0, *dm); // if not deep copied, this may crash or read freed memory
	// 	delete c2;
	// 	delete dm;
	// }

	return 0;
}

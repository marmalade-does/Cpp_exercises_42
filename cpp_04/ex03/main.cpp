/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:45:28 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/12 11:46:04 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

/// @brief this is a main function made by chat that is meant to test all the materias etc
/// @return 
int main()
{
	std::cout << "\n--- Test 0: Subject reference test ---" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n--- Test 1: getType() ---" << std::endl;
	{
		Ice ice;
		Cure cure;
		std::cout << "ice type:  " << ice.getType() << std::endl;
		std::cout << "cure type: " << cure.getType() << std::endl;
	}

	std::cout << "\n--- Test 2: clone() produces independent copies ---" << std::endl;
	{
		AMateria *a = new Ice();
		AMateria *b = a->clone();
		std::cout << "a type: " << a->getType() << std::endl;
		std::cout << "b type: " << b->getType() << std::endl;
		std::cout << "same pointer: " << (a == b ? "YES (bad)" : "NO (good)") << std::endl;
		Character dummy("dummy");
		a->use(dummy);
		b->use(dummy);
		delete a;
		delete b;
	}

	std::cout << "\n--- Test 3: equip fills slots 0-3, ignores 5th ---" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());

		Character c("fill");
		Character target("target");
		AMateria *arr[5];
		int i;
		i = 0;
		while (i < 5)
		{
			arr[i] = src.createMateria("ice");
			c.equip(arr[i]);
			i++;
		}
		c.use(0, target);
		c.use(1, target);
		c.use(2, target);
		c.use(3, target);
		std::cout << "(slot 4 was silently rejected)" << std::endl;
		delete arr[4];
	}

	std::cout << "\n--- Test 4: equip NULL --- no crash ---" << std::endl;
	{
		Character c("nulltest");
		c.equip(NULL);
		std::cout << "equip(NULL) survived" << std::endl;
	}

	std::cout << "\n--- Test 5: unequip puts materia on floor, NOT deleted ---" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());

		Character *c = new Character("drop");
		Character target("target");
		AMateria *m = src.createMateria("ice");

		c->equip(m);
		c->use(0, target);
		c->unequip(0);
		std::cout << "(slot 0 is now NULL)" << std::endl;
		c->use(0, target);
		std::cout << "(no output above = correct, slot is empty)" << std::endl;
		std::cout << "(materia is on the floor and will be freed by ~Character)" << std::endl;
		delete c;
	}

	std::cout << "\n--- Test 6: unequip out-of-range and empty slot --- no crash ---" << std::endl;
	{
		Character c("bounds");
		c.unequip(-1);
		c.unequip(4);
		c.unequip(0);
		std::cout << "all invalid unequip calls survived" << std::endl;
	}

	std::cout << "\n--- Test 7: use with invalid/empty indices --- no output, no crash ---" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Cure());

		Character c("useguard");
		Character target("target");
		c.equip(src.createMateria("cure"));

		c.use(-1, target);
		c.use(4, target);
		c.use(2, target);
		std::cout << "(no output from invalid indices above = correct)" << std::endl;
		c.use(0, target);
		std::cout << "(slot 0 above should have healed target)" << std::endl;
	}

	std::cout << "\n--- Test 8: createMateria unknown type returns NULL ---" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());

		AMateria *x = src.createMateria("fire");
		std::cout << "createMateria(\"fire\"): " << (x == NULL ? "NULL (correct)" : "not NULL (bad)") << std::endl;
		Character c("nullequip");
		c.equip(x);
		std::cout << "equip(NULL) survived" << std::endl;
	}

	std::cout << "\n--- Test 9: createMateria gives independent clones ---" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());

		AMateria *i1 = src.createMateria("ice");
		AMateria *i2 = src.createMateria("ice");
		std::cout << "same pointer: " << (i1 == i2 ? "YES (bad)" : "NO (good)") << std::endl;
		delete i1;
		std::cout << "i2 type after deleting i1: " << i2->getType() << std::endl;
		delete i2;
	}

	std::cout << "\n--- Test 10: learnMateria overflow (5th is deleted) ---" << std::endl;
	{
		MateriaSource full;
		full.learnMateria(new Ice());
		full.learnMateria(new Ice());
		full.learnMateria(new Ice());
		full.learnMateria(new Ice());
		full.learnMateria(new Cure());
		AMateria *m = full.createMateria("cure");
		std::cout << "createMateria(\"cure\") after overflow: " << (m == NULL ? "NULL (correct, cure was deleted)" : "not NULL (bad)") << std::endl;
		AMateria *m2 = full.createMateria("ice");
		std::cout << "createMateria(\"ice\") still works: " << (m2 ? m2->getType() : "NULL") << std::endl;
		delete m2;
	}

	std::cout << "\n--- Test 11: Character copy constructor (deep copy) ---" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character *original = new Character("original");
		Character target("target");
		original->equip(src.createMateria("ice"));
		original->equip(src.createMateria("cure"));

		Character copy(*original);
		delete original;

		std::cout << "Using copy after deleting original:" << std::endl;
		copy.use(0, target);
		copy.use(1, target);
	}

	std::cout << "\n--- Test 12: Character operator= (deep copy, cleans old inventory) ---" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character a("alpha");
		a.equip(src.createMateria("ice"));

		Character b("beta");
		b.equip(src.createMateria("cure"));

		Character target("target");

		std::cout << "b before assignment:" << std::endl;
		b.use(0, target);

		b = a;

		std::cout << "b after assignment (should be ice):" << std::endl;
		b.use(0, target);

		std::cout << "self-assignment:" << std::endl;
		a = a;
		a.use(0, target);
	}

	std::cout << "\n--- Test 13: MateriaSource copy constructor and operator= ---" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		MateriaSource src2(src);
		AMateria *m = src2.createMateria("ice");
		std::cout << "copy ctor: createMateria ice from copy: " << (m ? m->getType() : "NULL") << std::endl;
		delete m;

		MateriaSource src3;
		src3 = src;
		m = src3.createMateria("cure");
		std::cout << "op=: createMateria cure from assigned: " << (m ? m->getType() : "NULL") << std::endl;
		delete m;
	}

	std::cout << "\n--- Test 14: Re-equip after unequip (slot reuse) ---" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character c("reuse");
		Character target("target");

		AMateria *m1 = src.createMateria("ice");
		c.equip(m1);
		c.use(0, target);

		c.unequip(0);
		std::cout << "(unequipped, slot 0 is NULL)" << std::endl;
		c.use(0, target);
		std::cout << "(no output above = correct)" << std::endl;

		AMateria *m2 = src.createMateria("cure");
		c.equip(m2);
		std::cout << "(re-equipped slot 0 with cure)" << std::endl;
		c.use(0, target);
	}

	return 0;
}
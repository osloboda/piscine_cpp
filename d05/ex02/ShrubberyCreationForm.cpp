#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137)
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &D) : Form(D.getName(), 145, 137)
{
    *this = D;
    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm const &D)
{
    (void)D;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &D) const
{
    if (this->getSigned() && (D.getGrade() <= this->getGrade()))
    {
        std::string		file = this->getName() + "_shrubbery";
        std::ofstream	ofs(file);
        ofs << "              _{\\ _{\\{\\/}/}/}__\n"
               "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
               "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
               "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
               "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
               "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
               "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
               "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
               "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
               "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
               "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
               "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
               "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
               "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
               "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
               "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
               "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
               "              {){/ {\\/}{\\/} \\}\\}\n"
               "              (_)  \\.-'.-/\n"
               "          __...--- |'-.-'| --...__\n"
               "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
               " -\"    ' .  . '    |.'-._| '  . .  '   jro\n"
               " .  '-  '    .--'  | '-.'|    .  '  . '\n"
               "          ' ..     |'-_.-|\n"
               "  .  '  .       _.-|-._ -|-._  .  '  .\n"
               "              .'   |'- .-|   '.\n"
               "  ..-'   ' .  '.   `-._.-ґ   .'  '  - .\n"
               "   .-' '        '-._______.-'     '  .\n"
               "        .      ~,\n"
               "    .       .   |\\   .    ' '-.\n"
               "    ___________/  \\____________\n"
               "   /                           \\\n"
               "  |    Shrubbery Form has        |\n"
               "  |       been executed          |\n"
               "   \\___________________________/\n";
        ofs.close();
    }
    else if (!this->getSigned())
        std::cout << "A Bureaucrat must signed this form." << std::endl;
    else
        throw Form::GradeTooLowException();;
}

std::ostream& operator << (std::ostream &os, ShrubberyCreationForm const &D)
{
    os << "name: " << D.getName() << std::endl << "signing grade: " << D.getSGrade() << std::endl << "execution grade: " << D.getGrade() << std::endl;
    if (D.getSigned())
        os << "Form is signed." << std::endl;
    else
        os << "Form not signed yet." << std::endl;
    return (os);
}

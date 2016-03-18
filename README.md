# Лекции, прочитанные в рамках курса Основы Программирования на первом курсе ФФ НГУ

В рамках курса мною было прочитано две лекции:

*   [Лекция № 2](https://speakerdeck.com/nsu_op/2-priedstavlieniie-chisiel-v-pamiati):
    Представление чисел в памяти.
*   [Лекция № 3](https://speakerdeck.com/nsu_op/3-massivy-ukazatieli-pamiat):
    Массивы, указатели, память.

## Инструментарий

Лекции созданы с использованием LaTeX и пакета
[Beamer](https://www.ctan.org/pkg/beamer).

В боевом режиме была использована тема
[metropolis](https://github.com/matze/mtheme), требующая компиляции с помощью
`xelatex`; в отладочном режиме использовалась дефолтная тема Beamer и
компиляция с помощью `pdflatex` (ибо `xelatex` работает дооооолго).

Для рисунков активно использовался [PGF/TikZ](https://www.ctan.org/pkg/pgf).

![TikZ demo](https://github.com/cypok/op_lectures/raw/master/resources/tikz-demo.gif)

## Сборка

Для сборки рекомендуется использовать gem
[be9-rubbr](https://rubygems.org/gems/be9-rubbr)
(хотя можно собрать и вручную).

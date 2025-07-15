/* В базата от данни със схема:
DEPT (DEPTNO, DEPTNAME, MGRNO, ADMRDEPT, LOCATION);
EMPLOYEE (EMPNO, FIRSTNAME, MIDNAME, LASTNAME, WORKDEPT, HIREDATE, JOB, GENDER, BIRTHDATE, SALARY, BONUS, COMM);
PROJECT (PROJNO, PROJNAME, DEPTNO, RESPEMP, PRSTDATE, PRENDATE, MAJPROJ);
се съхранява информация за департаменти, работници и проекти.
    • Таблицата DEPT съдържа информация за номер и име на департамент (DEPTNO и DEPTNAME) и за номер на работник (MGRNO) –
      менажер за този департамент;
    • Таблицата EMPLOYEE съдържа информация за номер на работник (EMPNO), лични данни (FIRSTNAME, MIDINIT, LASTNAME),
      длъжност (JOB), заплата (SALARY) и номера на департамента (WORKDEPT), към който работи;
    • Таблицата PROJECT съдържа информация за номер (PROJNO) и име на проект (PROJNAME), начална и крайна дата на проекта
      (PRSTDATE, PRENDATE), департамента, към който е проектът (DEPTNO) и номера на работника – менажер на проекта (RESPEMP)
*/

-- А) Да се напише заявка, която извежда името на департамента, броя на проектите и сумарната заплата на менажерите на проекти
-- от този департамент.

SELECT D.DEPTNAME, COUNT(P.PROJNO) AS PROJECT_COUNT, SUM(E.SALARY) AS TOTAL_MANAGER_SALARY
FROM DEPT D JOIN PROJECT P ON D.DEPTNO = P.DEPTNO JOIN EMPLOYEE E ON P.RESPEMP = E.EMPNO GROUP BY D.DEPTNAME;

-- Б) Като се използва заявката от подточка А, да се напише заявка, която извежда името на департамента с най-висока сумарна заплата
-- на менажерите на проекти от този департамент. Забележка: Ако има повече департаменти със сумарна заплата равна на най-високата
-- сумарна заплата, тези департаменти също да се изведат

WITH DeptSalary AS (SELECT D.DEPTNAME, SUM(E.SALARY) AS TOTAL_MANAGER_SALARY
FROM DEPT D JOIN PROJECT P ON D.DEPTNO = P.DEPTNO JOIN EMPLOYEE E ON P.RESPEMP = E.EMPNO GROUP BY D.DEPTNAME)
SELECT DEPTNAME, TOTAL_MANAGER_SALARY FROM DeptSalary WHERE TOTAL_MANAGER_SALARY = (
  SELECT MAX(TOTAL_MANAGER_SALARY) FROM DeptSalary
);

-- В) Като се използва заявката от подточка А, да се напише заявка, която извежда името на департамента с най-много проекти.
-- Забележка: Ако има повече департаменти с брой на проектите, равен на максималния брой на проекти, тези департаменти също да се
-- изведат

WITH DeptProjects AS (SELECT D.DEPTNAME, COUNT(P.PROJNO) AS PROJECT_COUNT FROM DEPT D
JOIN PROJECT P ON D.DEPTNO = P.DEPTNO GROUP BY D.DEPTNAME)
SELECT DEPTNAME, PROJECT_COUNT FROM DeptProjects WHERE PROJECT_COUNT = (
  SELECT MAX(PROJECT_COUNT) FROM DeptProjects
);
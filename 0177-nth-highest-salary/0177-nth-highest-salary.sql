CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE X INT;
    SET X = N-1;
  RETURN (
      SELECT DISTINCT salary FROM Employee
      ORDER BY salary desc
      LIMIT 1 OFFSET X

  );
END
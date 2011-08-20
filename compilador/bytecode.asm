Header:
	Main Program:	10
	List Constants size:	20
	List class size:	10
	Size bytecode:	180
Constants:
		type:	5
		UID:1
		String:	(21)L'area del cercle es:
		type:	3
		UID:2
		Integer:	3
		type:	5
		UID:3
		String:	(1)

		type:	5
		UID:4
		String:	(27)El perimetre del cercle es:
		type:	3
		UID:5
		Integer:	3
		type:	5
		UID:6
		String:	(1)

		type:	3
		UID:7
		Integer:	3
		type:	3
		UID:8
		Integer:	1
		type:	3
		UID:9
		Integer:	0
		type:	5
		UID:10
		String:	(38)Escriu una de les següents opcións:

		type:	5
		UID:11
		String:	(12)t0=> sortir

		type:	5
		UID:12
		String:	(26)t1=> Calcular area cercle

		type:	5
		UID:13
		String:	(31)t2=> Calcular perimetre cercle

		type:	5
		UID:14
		String:	(41)t3=> Canviar cercle (Actualment té radi)
		type:	5
		UID:15
		String:	(1)

		type:	3
		UID:16
		Integer:	1
		type:	3
		UID:17
		Integer:	2
		type:	3
		UID:18
		Integer:	3
		type:	5
		UID:19
		String:	(41)Escriu el radi de la nova circonverencia:
		type:	5
		UID:20
		String:	(22)Revisa el que escrius

Class:
	UID:	1
	native?:	1
	name:	(7)Object
	Propieties (0):
	Methods (0):
	UID:	2
	native?:	1
	name:	(8)Boolean
	Propieties (0):
	Methods (3):
		UID:	1
		ByteCodeLine:	0
		Constructor:	0
		Name:	(15)Boolean(Object)
		UID:	2
		ByteCodeLine:	0
		Constructor:	0
		Name:	(3)and
		UID:	3
		ByteCodeLine:	0
		Constructor:	0
		Name:	(2)or
	UID:	3
	native?:	1
	name:	(8)Integer
	Propieties (0):
	Methods (11):
		UID:	2
		ByteCodeLine:	0
		Constructor:	0
		Name:	(15)Integer(Object)
		UID:	3
		ByteCodeLine:	0
		Constructor:	1
		Name:	(15)Integer(String)
		UID:	4
		ByteCodeLine:	0
		Constructor:	0
		Name:	(12)add(Integer)
		UID:	5
		ByteCodeLine:	0
		Constructor:	0
		Name:	(12)sub(Integer)
		UID:	6
		ByteCodeLine:	0
		Constructor:	0
		Name:	(12)mul(Integer)
		UID:	7
		ByteCodeLine:	0
		Constructor:	0
		Name:	(12)div(Integer)
		UID:	8
		ByteCodeLine:	0
		Constructor:	0
		Name:	(12)dif(Integer)
		UID:	9
		ByteCodeLine:	0
		Constructor:	0
		Name:	(14)equal(Integer)
		UID:	10
		ByteCodeLine:	0
		Constructor:	0
		Name:	(14)lower(Integer)
		UID:	11
		ByteCodeLine:	0
		Constructor:	0
		Name:	(16)greater(Integer)
		UID:	12
		ByteCodeLine:	0
		Constructor:	0
		Name:	(8)toString
	UID:	4
	native?:	1
	name:	(7)String
	Propieties (0):
	Methods (3):
		UID:	3
		ByteCodeLine:	0
		Constructor:	0
		Name:	(14)String(Object)
		UID:	4
		ByteCodeLine:	0
		Constructor:	0
		Name:	(11)add(String)
		UID:	5
		ByteCodeLine:	0
		Constructor:	0
		Name:	(9)toInteger
	UID:	5
	native?:	1
	name:	(5)list
	Propieties (0):
	Methods (10):
		UID:	4
		ByteCodeLine:	0
		Constructor:	0
		Name:	(12)list(Object)
		UID:	5
		ByteCodeLine:	0
		Constructor:	1
		Name:	(4)list
		UID:	6
		ByteCodeLine:	0
		Constructor:	0
		Name:	(12)get(Integer)
		UID:	7
		ByteCodeLine:	0
		Constructor:	0
		Name:	(6)length
		UID:	8
		ByteCodeLine:	0
		Constructor:	0
		Name:	(11)add(Object)
		UID:	9
		ByteCodeLine:	0
		Constructor:	0
		Name:	(16)addFirst(Object)
		UID:	10
		ByteCodeLine:	0
		Constructor:	0
		Name:	(5)first
		UID:	11
		ByteCodeLine:	0
		Constructor:	0
		Name:	(11)removeFirst
		UID:	12
		ByteCodeLine:	0
		Constructor:	0
		Name:	(4)last
		UID:	13
		ByteCodeLine:	0
		Constructor:	0
		Name:	(3)pop
	UID:	6
	native?:	1
	name:	(5)File
	Propieties (0):
	Methods (4):
		UID:	5
		ByteCodeLine:	0
		Constructor:	0
		Name:	(12)File(Object)
		UID:	6
		ByteCodeLine:	0
		Constructor:	1
		Name:	(20)File(String, String)
		UID:	7
		ByteCodeLine:	0
		Constructor:	0
		Name:	(13)write(String)
		UID:	8
		ByteCodeLine:	0
		Constructor:	0
		Name:	(4)read
	UID:	7
	native?:	1
	name:	(6)Shell
	Propieties (0):
	Methods (4):
		UID:	6
		ByteCodeLine:	0
		Constructor:	0
		Name:	(13)Shell(Object)
		UID:	7
		ByteCodeLine:	0
		Constructor:	0
		Name:	(14)stdout(String)
		UID:	8
		ByteCodeLine:	0
		Constructor:	0
		Name:	(5)stdin
		UID:	9
		ByteCodeLine:	0
		Constructor:	0
		Name:	(14)stderr(String)
	UID:	8
	native?:	0
	name:	(7)Figura
	Propieties (0):
	Methods (3):
		UID:	7
		ByteCodeLine:	0
		Constructor:	0
		Name:	(14)Figura(Object)
		UID:	8
		ByteCodeLine:	2
		Constructor:	0
		Name:	(12)calcularArea
		UID:	9
		ByteCodeLine:	4
		Constructor:	0
		Name:	(17)calcularPerimetre
	UID:	9
	native?:	0
	name:	(7)Cercle
	Propieties (1):
		UID:	6
		Name:	 (1)r
	Methods (6):
		UID:	7
		ByteCodeLine:	0
		Constructor:	0
		Name:	(14)Figura(Object)
		UID:	8
		ByteCodeLine:	25
		Constructor:	0
		Name:	(12)calcularArea
		UID:	9
		ByteCodeLine:	48
		Constructor:	0
		Name:	(17)calcularPerimetre
		UID:	10
		ByteCodeLine:	6
		Constructor:	0
		Name:	(14)Cercle(Object)
		UID:	11
		ByteCodeLine:	8
		Constructor:	1
		Name:	(15)Cercle(Integer)
		UID:	12
		ByteCodeLine:	20
		Constructor:	0
		Name:	(7)getRadi
	UID:	10
	native?:	0
	name:	(6)prova
	Propieties (1):
		UID:	7
		Name:	 (3)fig
	Methods (3):
		UID:	8
		ByteCodeLine:	71
		Constructor:	0
		Name:	(13)prova(Object)
		UID:	9
		ByteCodeLine:	73
		Constructor:	1
		Name:	(5)prova
		UID:	10
		ByteCodeLine:	80
		Constructor:	0
		Name:	(10)main(list)
ByteCode:
	0:RET	-1	
	1:SIZE_INSTRUCTIONS	7	
	2:RET	-1	
	3:SIZE_INSTRUCTIONS	8	
	4:RET	-1	
	5:SIZE_INSTRUCTIONS	9	
	6:RET	-1	
	7:SIZE_INSTRUCTIONS	10	
	8:PUSH_TOP	0	(reservant:p)
	9:LOAD_PRIVATE	0	(this)
	10:LOAD_PRIVATE	1	(rad)
	11:STORE_ATTR	6	
	12:LOAD_PRIVATE	0	(this)
	13:LOAD_ATTR	6	(r)
	14:STORE_PRIVATE	2	
	15:LOAD_PRIVATE	0	(this)
	16:LOAD_PRIVATE	2	(p)
	17:STORE_ATTR	6	
	18:RET	-1	
	19:SIZE_INSTRUCTIONS	11	
	20:LOAD_PRIVATE	0	(this)
	21:LOAD_ATTR	6	(r)
	22:RET	0	
	23:RET	-1	
	24:SIZE_INSTRUCTIONS	12	
	25:LOAD_CLASS	7	(Shell)
	26:LOAD_METHOD	7	(stdout(String))
	27:LOAD_CONSTANT	1	(L'area del cercle es:)
	28:LOAD_METHOD	4	(add(String))
	29:LOAD_PRIVATE	0	(this)
	30:LOAD_ATTR	6	(r)
	31:LOAD_METHOD	6	(mul(Integer))
	32:LOAD_PRIVATE	0	(this)
	33:LOAD_ATTR	6	(r)
	34:LOAD_METHOD	6	(mul(Integer))
	35:LOAD_CONSTANT	2	(3)
	36:CALL	1	(mul(Integer))
	37:CALL	1	(mul(Integer))
	38:LOAD_METHOD	12	(toString)
	39:CALL	0	(toString)
	40:LOAD_METHOD	4	(add(String))
	41:LOAD_CONSTANT	3	(
)
	42:CALL	1	(add(String))
	43:CALL	1	(add(String))
	44:CALL	1	(stdout(String))
	45:POP_TOP	0	
	46:RET	-1	
	47:SIZE_INSTRUCTIONS	8	
	48:LOAD_CLASS	7	(Shell)
	49:LOAD_METHOD	7	(stdout(String))
	50:LOAD_CONSTANT	4	(El perimetre del cercle es:)
	51:LOAD_METHOD	4	(add(String))
	52:LOAD_PRIVATE	0	(this)
	53:LOAD_ATTR	6	(r)
	54:LOAD_METHOD	6	(mul(Integer))
	55:LOAD_PRIVATE	0	(this)
	56:LOAD_ATTR	6	(r)
	57:LOAD_METHOD	6	(mul(Integer))
	58:LOAD_CONSTANT	5	(3)
	59:CALL	1	(mul(Integer))
	60:CALL	1	(mul(Integer))
	61:LOAD_METHOD	12	(toString)
	62:CALL	0	(toString)
	63:LOAD_METHOD	4	(add(String))
	64:LOAD_CONSTANT	6	(
)
	65:CALL	1	(add(String))
	66:CALL	1	(add(String))
	67:CALL	1	(stdout(String))
	68:POP_TOP	0	
	69:RET	-1	
	70:SIZE_INSTRUCTIONS	9	
	71:RET	-1	
	72:SIZE_INSTRUCTIONS	8	
	73:LOAD_CLASS	9	(Cercle)
	74:LOAD_METHOD	11	(Cercle(Integer))
	75:LOAD_CONSTANT	7	(3)
	76:CALL	1	(Cercle(Integer))
	77:STORE_ATTR	7	
	78:RET	-1	
	79:SIZE_INSTRUCTIONS	9	
	80:PUSH_TOP	0	(reservant:i)
	81:LOAD_CONSTANT	8	(1)
	82:STORE_PRIVATE	2	
	83:LOAD_PRIVATE	2	(i)
	84:LOAD_METHOD	8	(dif(Integer))
	85:LOAD_CONSTANT	9	(0)
	86:CALL	1	(dif(Integer))
	87:GOTO_FALSE	178	
	88:LOAD_CLASS	7	(Shell)
	89:LOAD_METHOD	7	(stdout(String))
	90:LOAD_CONSTANT	10	(Escriu una de les següents opcións:
)
	91:CALL	1	(stdout(String))
	92:POP_TOP	0	
	93:LOAD_CLASS	7	(Shell)
	94:LOAD_METHOD	7	(stdout(String))
	95:LOAD_CONSTANT	11	(t0=> sortir
)
	96:CALL	1	(stdout(String))
	97:POP_TOP	0	
	98:LOAD_CLASS	7	(Shell)
	99:LOAD_METHOD	7	(stdout(String))
	100:LOAD_CONSTANT	12	(t1=> Calcular area cercle
)
	101:LOAD_METHOD	4	(add(String))
	102:LOAD_CONSTANT	13	(t2=> Calcular perimetre cercle
)
	103:LOAD_METHOD	4	(add(String))
	104:LOAD_CONSTANT	14	(t3=> Canviar cercle (Actualment té radi))
	105:LOAD_METHOD	4	(add(String))
	106:LOAD_CLASS	9	(Cercle)
	107:LOAD_METHOD	10	(Cercle(Object))
	108:LOAD_PRIVATE	0	(this)
	109:LOAD_ATTR	7	(fig)
	110:CALL	1	(Cercle(Object))
	111:LOAD_METHOD	12	(getRadi)
	112:CALL	0	(getRadi)
	113:LOAD_METHOD	12	(toString)
	114:CALL	0	(toString)
	115:LOAD_METHOD	4	(add(String))
	116:LOAD_CONSTANT	15	(
)
	117:CALL	1	(add(String))
	118:CALL	1	(add(String))
	119:CALL	1	(add(String))
	120:CALL	1	(add(String))
	121:CALL	1	(stdout(String))
	122:POP_TOP	0	
	123:LOAD_CLASS	7	(Shell)
	124:LOAD_METHOD	8	(stdin)
	125:CALL	0	(stdin)
	126:LOAD_METHOD	5	(toInteger)
	127:CALL	0	(toInteger)
	128:STORE_PRIVATE	2	
	129:LOAD_PRIVATE	2	(i)
	130:LOAD_METHOD	9	(equal(Integer))
	131:LOAD_CONSTANT	16	(1)
	132:CALL	1	(equal(Integer))
	133:GOTO_FALSE	140	
	134:LOAD_PRIVATE	0	(this)
	135:LOAD_ATTR	7	(fig)
	136:LOAD_METHOD	8	(calcularArea)
	137:CALL	0	(calcularArea)
	138:POP_TOP	0	
	139:GOTO	83	
	140:LOAD_PRIVATE	2	(i)
	141:LOAD_METHOD	9	(equal(Integer))
	142:LOAD_CONSTANT	17	(2)
	143:CALL	1	(equal(Integer))
	144:GOTO_FALSE	151	
	145:LOAD_PRIVATE	0	(this)
	146:LOAD_ATTR	7	(fig)
	147:LOAD_METHOD	9	(calcularPerimetre)
	148:CALL	0	(calcularPerimetre)
	149:POP_TOP	0	
	150:GOTO	83	
	151:LOAD_PRIVATE	2	(i)
	152:LOAD_METHOD	9	(equal(Integer))
	153:LOAD_CONSTANT	18	(3)
	154:CALL	1	(equal(Integer))
	155:GOTO_FALSE	171	
	156:LOAD_CLASS	7	(Shell)
	157:LOAD_METHOD	7	(stdout(String))
	158:LOAD_CONSTANT	19	(Escriu el radi de la nova circonverencia:)
	159:CALL	1	(stdout(String))
	160:POP_TOP	0	
	161:LOAD_CLASS	9	(Cercle)
	162:LOAD_METHOD	11	(Cercle(Integer))
	163:LOAD_CLASS	7	(Shell)
	164:LOAD_METHOD	8	(stdin)
	165:CALL	0	(stdin)
	166:LOAD_METHOD	5	(toInteger)
	167:CALL	0	(toInteger)
	168:CALL	1	(Cercle(Integer))
	169:STORE_ATTR	7	
	170:GOTO	83	
	171:LOAD_CLASS	7	(Shell)
	172:LOAD_METHOD	7	(stdout(String))
	173:LOAD_CONSTANT	20	(Revisa el que escrius
)
	174:CALL	1	(stdout(String))
	175:POP_TOP	0	
	176:GOTO	83	
	177:GOTO	83	
	178:RET	-1	
	179:SIZE_INSTRUCTIONS	10	

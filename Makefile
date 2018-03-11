# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 21:48:14 by vgladush          #+#    #+#              #
#    Updated: 2018/03/10 15:56:09 by vgladush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH = checker
NAME_PS = push_swap

GC_FLGS = gcc -Wall -Wextra -Werror

SRC_PSW = ./srcs_push_swap
SRC_CHK = ./srcs_checker
SRC_OTH = ./srcs
INC_DIR = ./includes/ $(LB_PATH)/includes/
OBJ_PSW = ./obj_push_swap
OBJ_CHK = ./obj_checker
LB_PATH = ./libft/
LB_LINK	= -L ./libft -lft
PS_SRCS	=

TH_SRCS	=

CH_SRCS	=

PS_OBJS	= $(PS_SRCS:.c=.o)
TH_OBJS	= $(TH_SRCS:.c=.o)
CH_OBJS	= $(CH_SRCS:.c=.o)
OBJS_PS	= $(addprefix $(OBJ_PSW), $(PS_OBJS) $(TH_OBJS))
OBJS_CH	= $(addprefix $(OBJ_CHK), $(CH_OBJS) $(TH_OBJS))
INC 	= $(addprefix -I, $(INC_DIR))

BLK = '\x1B[0;30m'
RED = '\x1B[0;31m'
GRN = '\x1B[0;32m'
BRW = '\x1B[0;33m'
BLE = '\x1B[0;34m'
PUR = '\x1B[0;35m'
CYN = '\x1B[0;36m'
LGY = '\x1B[0;37m'
DGY = '\x1B[1;30m'
LRD = '\x1B[1;31m'
LGR = '\x1B[1;32m'
YEL = '\x1B[1;33m'
LBL = '\x1B[1;34m'
FIL = '\x1B[1;35m'
LCN = '\x1B[1;36m'
WHT = '\x1B[1;37m'
WCR = '\x1B[0m'

all: $(NAME)

$(NAME): ./Includes/le_min.h $(OBJ)
	@make -C $(LB_PATH)
	@gcc -o $(NAME) $(OBJ) $(LB_LINK)
	@echo $(GRN)$(NAME) "ready"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(GC_FLGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LB_PATH) clean
	@rm -rf $(OBJ_DIR)
	@echo $(LRD)$(NAME) "deleted"

fclean:
	@make -C $(LB_PATH) fclean
	@rm -rf $(OBJ_DIR)
	@echo $(LRD)objects $(NAME) "deleted"
	@rm -f $(NAME)
	@echo $(RED)$(NAME) "deleted"

re: fclean all

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:41:58 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 20:00:36 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ops_core.h"

t_bool			ft_ld(t_battle *battle, t_op *op, t_u16 pc)
{
	t_u8		byte_coding;
	t_u32		value;
	t_uint		*reg;

	if ((byte_coding = get_byte_coding(battle, op)) == 0)
		return (false);
	if ((byte_code_arg(byte_coding, 0) & IND_CODE) == IND_CODE)
		value = get_indirect(battle, pc, IDX_MOD);
	else
		value = vm_memget32(battle);
	if ((reg = get_register(battle)) == NULL)
		return (false);
	*reg = value;
	if (*reg)
		battle->curr_process->carry = 0;
	else
		battle->curr_process->carry = 1;
	return (true);
}
